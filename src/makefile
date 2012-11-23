CPP = g++
CFLAGS = -Wall -g -Werror
SDLFLAGS = -lSDL -lGLU -lGL
BUILD = ../build

all: $(BUILD)/fractalRender TwoDStruct.o

$(BUILD)/fractalRender: fractalRender.cpp
	$(CPP) $(CFLAGS) -o $(BUILD)/fractalRender fractalRender.cpp $(SDLFLAGS)

TwoDStruct.o: TwoDStruct.h TwoDStruct.cpp
	$(CPP) $(CFLAGS) -c TwoDStruct.cpp

clean:
	rm *.o
