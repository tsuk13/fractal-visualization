#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>

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
   float angle;
   while( events() )
   {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glLoadIdentity();
      glTranslatef(0,0, -10);
      glRotatef(angle, 0, 0, 1);

      glBegin(GL_QUADS);
      glColor3ub(255, 000, 000); glVertex2f(-1,  1);
      glColor3ub(000, 255, 000); glVertex2f( 1,  1);
      glColor3ub(000, 000, 255); glVertex2f( 1, -1);
      glColor3ub(255, 255, 000); glVertex2f(-1, -1);
      glEnd();

   	SDL_GL_SwapBuffers();
      // Check keypresses
      if( key[SDLK_RIGHT] ){ angle-=0.5; }
      if( key[SDLK_LEFT ] ){ angle+=0.5; }
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
