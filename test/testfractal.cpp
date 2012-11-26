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
 float size = .5;
   while( events() )
   {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
         glLoadIdentity(); //setup our global rotation
         glTranslatef(.5, 0, -10);
         glScalef(.5, .5, 1);
         glRotatef(-45, 0, 0, 1);
         glBegin(GL_QUADS);
         glColor3ub(255, 255, 255); glVertex2f(-size,  size);
         glColor3ub(255, 255, 255); glVertex2f( size,  size);
         glColor3ub(255, 255, 255); glVertex2f( size, -size);
         glColor3ub(255, 255, 255); glVertex2f(-size, -size);
         glEnd();

      SDL_GL_SwapBuffers();
      // Check keypresses
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
