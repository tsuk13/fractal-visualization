CPP = g++
CFLAGS = -Wall -g
SDLFLAGS = -lSDL -lGLU -lGL

testlib: testlib.cpp
	$(CPP) $(CFLAGS) -o testlib testlib.cpp $(SDLFLAGS)
