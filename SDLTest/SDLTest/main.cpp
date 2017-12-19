
#include <iostream>
#include <stdio.h>

#include <SDL.h>

#include "WindowScreen.h"


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;







#undef main

int main(int argc, char* args[])
{
	
	WindowScreen win(SCREEN_WIDTH, SCREEN_HEIGHT);

	if (!win.loadMedia())
	{
		printf("Failed to load media!\n");
	}
	else
	{
		SDL_LowerBlit(win.getHelloWorld(), nullptr, win.getScreenSurface(), nullptr);
		SDL_UpdateWindowSurface(win.getWindow());
	}

	SDL_Delay(2000);

	return 0;
}


