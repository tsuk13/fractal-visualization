CPP = g++
CFLAGS = -Wall -g
SDLFLAGS = -lSDL -lGLU -lGL

all: testlib testfractal

testlib: testlib.cpp
	$(CPP) $(CFLAGS) -o testlib testlib.cpp $(SDLFLAGS)

testfractal: testfractal.cpp
	$(CPP) $(CFLAGS) -o testfractal testfractal.cpp $(SDLFLAGS)
