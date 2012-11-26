CPP = g++
CFLAGS = -Wall -g -Werror
SDLFLAGS = -lSDL -lGLU -lGL
BUILD = ../build

all: $(BUILD)/fractalRender TwoDStruct.o ThreeDStruct.o

$(BUILD)/fractalRender: fractalRender.cpp TwoDStruct.o ThreeDStruct.o
	$(CPP) $(CFLAGS) -o $(BUILD)/fractalRender fractalRender.cpp $(SDLFLAGS) TwoDStruct.o ThreeDStruct.o

TwoDStruct.o: TwoDStruct.h TwoDStruct.cpp
	$(CPP) $(CFLAGS) -c TwoDStruct.cpp

ThreeDStruct.o: ThreeDStruct.h ThreeDStruct.cpp
	$(CPP) $(CFLAGS) -c ThreeDStruct.cpp

clean:
	rm -f *.o
