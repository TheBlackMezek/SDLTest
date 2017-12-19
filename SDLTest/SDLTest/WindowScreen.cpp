#include "WindowScreen.h"

#include <iostream>




WindowScreen::WindowScreen(size_t width, size_t height)
	: SCREEN_WIDTH(width), SCREEN_HEIGHT(height)
{
	window = nullptr;

	screenSurface = nullptr;

	helloWorld = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == nullptr)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);

			SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(
				screenSurface->format, 0xFF, 0xFF, 0xFF));

			SDL_UpdateWindowSurface(window);
		}
	}
}


WindowScreen::~WindowScreen()
{
	SDL_FreeSurface(helloWorld);
	helloWorld = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();
}





bool WindowScreen::loadMedia()
{
	bool success = true;

	helloWorld = SDL_LoadBMP("HelloWorld.bmp");
	if (helloWorld == nullptr)
	{
		printf("Unable to load imate %s! SDL Error: %s\n", "HelloWorld.bmp", SDL_GetError());
		success = false;
	}

	return success;
}




SDL_Surface* WindowScreen::getHelloWorld()
{
	return helloWorld;
}
SDL_Surface* WindowScreen::getScreenSurface()
{
	return helloWorld;
}
SDL_Window* WindowScreen::getWindow()
{
	return window;
}
