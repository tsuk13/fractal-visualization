CPP = g++
CFLAGS = -Wall -g -Werror
SDLFLAGS = -lSDL -lGLU -lGL
BUILD = ../build

all: $(BUILD)/testlib $(BUILD)/testfractal

$(BUILD)/testlib: testlib.cpp
	$(CPP) $(CFLAGS) -o $(BUILD)/testlib testlib.cpp $(SDLFLAGS)

$(BUILD)/testfractal: testfractal.cpp
	$(CPP) $(CFLAGS) -o $(BUILD)/testfractal testfractal.cpp $(SDLFLAGS)

clean:
	rm *.o
