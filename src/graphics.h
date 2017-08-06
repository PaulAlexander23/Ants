#pragma once

#include "main.h"

class graphics
{
public:
	graphics(bool* quit, int ScreenWidth, int ScreenHeight);
	~graphics();

	SDL_Renderer* get_renderer();
	SDL_Event* get_main_event();

	void begin();
	void end();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* main_event;

};

