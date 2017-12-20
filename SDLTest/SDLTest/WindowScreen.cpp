#include "WindowScreen.h"

#include <iostream>



const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window;

SDL_Surface* screenSurface;

SDL_Surface* helloWorld;




void init()
{
	window = NULL;

	screenSurface = NULL;

	helloWorld = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);

			//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(
			//	screenSurface->format, 0x90, 0x90, 0x90));
			//
			//SDL_UpdateWindowSurface(window);
		}
	}
}

bool loadMedia()
{
	bool success = true;

	helloWorld = SDL_LoadBMP("HelloWorld.bmp");
	if (helloWorld == NULL)
	{
		printf("Unable to load imate %s! SDL Error: %s\n", "HelloWorld.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void close()
{
	SDL_FreeSurface(helloWorld);
	helloWorld = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}
