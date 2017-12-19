#pragma once

#include <SDL.h>



class WindowScreen
{
private:

	SDL_Window* window;

	SDL_Surface* screenSurface;

	SDL_Surface* helloWorld;


public:
	WindowScreen(size_t width, size_t height);
	~WindowScreen();

	const size_t SCREEN_WIDTH;
	const size_t SCREEN_HEIGHT;

	bool loadMedia();

	SDL_Surface* getHelloWorld();
	SDL_Surface* getScreenSurface();
	SDL_Window* getWindow();
};

