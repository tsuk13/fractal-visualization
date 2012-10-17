CPP = g++
CFLAGS = -Wall -g
SDLFLAGS = -lSDL -lGLU -lGL

all: testlib testfractal fractalRender

testlib: testlib.cpp
	$(CPP) $(CFLAGS) -o testlib testlib.cpp $(SDLFLAGS)

testfractal: testfractal.cpp
	$(CPP) $(CFLAGS) -o testfractal testfractal.cpp $(SDLFLAGS)

fractalRender: fractalRender.cpp
	$(CPP) $(CFLAGS) -o fractalRender fractalRender.cpp $(SDLFLAGS)
