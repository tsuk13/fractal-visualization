#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <cstdlib>
#include <ctime>

#define window_width  640
#define window_height 480

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
      
      
      int numPoints = 100; //number of points used in fractal
      int deep = 100; //how many iterations of rules
      srand(time(NULL));
      for(int i = 0; i<numPoints; i++){
         glLoadIdentity(); //setup our global rotation
         glTranslatef(0,0, -10);
         glRotatef(angle, 0, 0, 1);
         glScalef(zoom, zoom, 0);
         for(int j = 0; j<deep; j++){
           if(rand()%2 == 0){
             glScalef(.7071, .7071, 0); //this is our process to create fractal
             glRotatef(45, 0, 0, 1);
           }
           else{
             glScalef(.7071, .7071, 0);
             glRotatef(-45, 0, 0, 1);
             glTranslatef(1, 0, 0);
           }
           glBegin(GL_POINTS);
           glColor3ub(255, 000, 000); glVertex2f(-1,  1);
           glEnd();
         }
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
