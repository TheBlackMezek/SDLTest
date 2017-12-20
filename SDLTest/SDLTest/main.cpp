
#include <iostream>
#include <stdio.h>

#include <SDL.h>

#include "WindowScreen.h"







#undef main

int main(int argc, char* args[])
{
	
	init();

	if(!loadMedia())
	{
		printf("Failed to load media!\n");
	}
	else
	{
		if (SDL_BlitSurface(helloWorld, NULL, screenSurface, NULL) != 0)
		{
			printf("Failed to blit! SDL_Error: %s\n", SDL_GetError());
		}
		if (SDL_UpdateWindowSurface(window) != 0)
		{
			printf("Failed to update window surface! SDL_Error: %s\n", SDL_GetError());
		}
	}

	SDL_Delay(2000);

	close();

	return 0;
}






