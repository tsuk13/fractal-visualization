#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <cassert>
#include "TwoDStruct.h"

using std::cout;
using std::cin;
using std::vector;

#define window_width  640
#define window_height 480

//Fractal Information
vector<TwoDStruct*> imageVec;
int numPoints = 10000; //number of points used in fractal
int deep = 15; //how many iterations of rules
double size = 2; // size of points

// Keydown booleans
bool key[321];

// Process pending events
bool events()
{
   SDL_Event event;
   if( SDL_PollEvent(&event) )
   {
      switch( event.type )
      {
         case SDL_KEYDOWN : key[ event.key.keysym.sym ]=true ;   break;
         case SDL_KEYUP   : key[ event.key.keysym.sym ]=false;   break;
         case SDL_QUIT    : return false; break;
      }
   }
   return true;
}

void main_loop_function()
{
   float angle = 0;
   float zoom = 1;
   while( events() )
   {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      
      srand(131313); 
      for(int i = 0; i<numPoints; i++){
         glLoadIdentity(); //setup our global rotation
         glTranslatef(0,0, -10);
         glRotatef(angle, 0, 0, 1);
         glScalef(zoom, zoom, 0);
         //this is our process to create fractal
         for(int j = 0; j<deep; j++){ 
           int r = rand() % imageVec.size();
           glScalef(imageVec[r]->getScale(), imageVec[r]->getScale(), 0); 
           glRotatef(imageVec[r]->getRotate(), 0, 0, 1);
           glTranslatef(imageVec[r]->getTranX(),imageVec[r]->getTranY(),0);
         }
         glBegin(GL_QUADS);
         glColor3ub(255, 255, 255); glVertex2f(-size,  size);
         glColor3ub(255, 255, 255); glVertex2f( size,  size);
         glColor3ub(255, 255, 255); glVertex2f( size, -size);
         glColor3ub(255, 255, 255); glVertex2f(-size, -size);
         glEnd();
      }
      SDL_GL_SwapBuffers();
      // Check keypresses
      if( key[SDLK_RIGHT] ){ angle-=0.5; }
      if( key[SDLK_LEFT ] ){ angle+=0.5; }
      if( key[SDLK_UP ] ){ zoom *= 1.01; }
      if( key[SDLK_DOWN ] ){ zoom *= 0.99; }
   }
}

// Initialze OpenGL perspective matrix
void GL_Setup(int width, int height)
{
   glViewport( 0, 0, width, height );
   glMatrixMode( GL_PROJECTION );
   glEnable( GL_DEPTH_TEST );
   gluPerspective( 45, (float)width/height, 0.1, 100 );
   glMatrixMode( GL_MODELVIEW );
}

int main()
{
   //User Input prompt
   int numImages;
   cout << "\nInput number of images: ";
   cin >> numImages;
   assert(numImages > 0);
   for(int i = 1; i <= numImages; i++){
     cout << "\nInput image " << i << "'s scale factor: ";
     float s;
     cin >> s;
     cout << "Input image " << i << "'s clockwise rotation(degrees): ";
     float r;
     cin >> r;
     cout << "Input image " << i << "'s translation in X: ";
     float tX;
     cin >> tX;
     cout << "Input image " << i << "'s translation in Y: ";
     float tY;
     cin >> tY;
     //input all this info into the structure object
     imageVec.push_back(new TwoDStruct(s,r,tX,tY));
   }
   cout << "\nCustom Render Settings?[y/n]";
   char c;
   cin >> c;
   if( c == 'y' || c == 'Y'){
     cout << "\nNumber of points[default: " << numPoints << "]: ";
     cin >> numPoints;
     assert(numPoints > 0);
     cout << "\nDepth of points[default: " << deep << "]: ";
     cin >> deep;
     assert(deep > 0);
     cout << "\nSize of points[default: " << size << "]: ";
     cin >> size;
     assert(size > 0);
   }

   // Initialize SDL with best video mode
   SDL_Init(SDL_INIT_VIDEO);
   const SDL_VideoInfo* info = SDL_GetVideoInfo();	
   int vidFlags = SDL_OPENGL | SDL_GL_DOUBLEBUFFER;
   if (info->hw_available) {vidFlags |= SDL_HWSURFACE;}
   else {vidFlags |= SDL_SWSURFACE;}
   int bpp = info->vfmt->BitsPerPixel;
   SDL_SetVideoMode(window_width, window_height, bpp, vidFlags);

   GL_Setup(window_width, window_height);

   main_loop_function();
}
