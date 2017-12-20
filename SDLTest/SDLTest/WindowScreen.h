#pragma once

#include <SDL.h>





extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;


extern SDL_Window* window;

extern SDL_Surface* screenSurface;

extern SDL_Surface* helloWorld;

void init();
bool loadMedia();
void close();

