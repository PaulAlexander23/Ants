#include "graphics.h"

graphics::graphics(bool* quit, int ScreenWidth, int ScreenHeight)
{

	window = NULL;
	window = SDL_CreateWindow("TitleScreen", 40, 40, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "Window counldn't be created" << std::endl;
		*quit = true;
	}
	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_ACCELERATED);
	main_event = new SDL_Event();
}

graphics::~graphics()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete main_event;
}

SDL_Renderer* graphics::get_renderer()
{
	return renderer;
}

SDL_Event* graphics::get_main_event()
{
	return main_event;
}

void graphics::begin()
{
	SDL_PollEvent(main_event);
	SDL_RenderClear(renderer);
}

void graphics::end()
{
	SDL_RenderPresent(renderer);
}
