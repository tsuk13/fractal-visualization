#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <cassert>
#include "TwoDStruct.h"
#include "ThreeDStruct.h"

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
bool twoD = true;

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
   //float angle = 0;
   float zoom = 1;
   float tranX = 0;
   float tranY = 0;
   while( events() )
   {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      
      srand(131313); 
      for(int i = 0; i<numPoints; i++){
         glLoadIdentity(); //setup our global rotation

         //code for twoD specific render
         if(twoD){
           //Camera
           glScalef(zoom, zoom, 1);
           glTranslatef(tranX,tranY, -5);
           //this is our process to create fractal
           //loop to apply random transformations of the inputed ones
           for(int j = 0; j<deep; j++){ 
             int r = rand() % imageVec.size();
             glTranslatef(imageVec[r]->getTranX(),imageVec[r]->getTranY(),0);
             glScalef(imageVec[r]->getScale(), imageVec[r]->getScale(), 1);
             glRotatef(-imageVec[r]->getRotate(), 0, 0, 1); 
           }
           //Draw
           glBegin(GL_QUADS);
           glColor3ub(255, 255, 255); glVertex2f( 0,  0);
           glColor3ub(255, 255, 255); glVertex2f( size,  0);
           glColor3ub(255, 255, 255); glVertex2f( size, -size);
           glColor3ub(255, 255, 255); glVertex2f( 0, -size);
           glEnd();
         }

         //code for threeD specific render
         else{
         }
      }
      SDL_GL_SwapBuffers();
      // Check keypresses 
      if( key[SDLK_UP ] ){ zoom *= 1.05; }
      if( key[SDLK_DOWN ] ){ zoom *= 0.95; }
      //twoD specfic controls
      if(twoD){
        if( key[SDLK_w] ){ tranY -= .2/zoom; } 
        if( key[SDLK_s] ){ tranY += .2/zoom; }
        if( key[SDLK_a] ){ tranX += .2/zoom; }
        if( key[SDLK_d] ){ tranX -= .2/zoom; }
      }
      //threeD specfic controls
      else{
      }
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
   cout << "\n2D mode or 3D mode?[2/3]: ";
   int mode;
   cin >> mode;
   assert(mode == 2 || mode == 3);
   twoD = (mode == 2);
   int numImages;
   cout << "\nInput number of images: ";
   cin >> numImages;
   assert(numImages > 0);
   for(int i = 1; i <= numImages; i++){
     //twoD specific input
     if(twoD){
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
     //threeD specfic input
     else{
     }
   }
   cout << "\nCustom Render Settings?[y/n]";
   char c;
   cin >> c;
   if( c == 'y' || c == 'Y'){
     cout << "\nNumber of points[default: " << numPoints << "]: ";
     cin >> numPoints;
     assert(numPoints > 0);
     cout << "Depth of points[default: " << deep << "]: ";
     cin >> deep;
     assert(deep > 0);
     cout << "Size of points[default: " << size << "]: ";
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
