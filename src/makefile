CPP = g++
CFLAGS = -Wall -g -Werror
SDLFLAGS = -lSDL -lGLU -lGL
BUILD = ../build

all: $(BUILD)/fractalRender

$(BUILD)/fractalRender: fractalRender.cpp
	$(CPP) $(CFLAGS) -o $(BUILD)/fractalRender fractalRender.cpp $(SDLFLAGS)

clean:
	rm *.o
