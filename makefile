CPP = g++
CFLAGS = -Wall -g -Werror
SDLFLAGS = -lSDL -lGLU -lGL

all: build/testlib build/testfractal build/fractalRender

build/testlib: test/testlib.cpp
	cd test; $(MAKE)

build/testfractal: test/testfractal.cpp
	cd test; $(MAKE)

build/fractalRender: src/fractalRender.cpp
	cd src; $(MAKE)

clean:
	rm -f build/*
	cd test; $(MAKE) clean
	cd src; $(MAKE) clean
