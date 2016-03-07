//Simple ants

#include "Header1.h"
#include "cSDL.h"
#include "ant.h"
#include "colony.h"

using namespace std;

int wmain(int argc, char **argv){

	//Setting up SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	int SCREENHEIGHT = 800;
	int SCREENWIDTH = 1280;

	bool quit = false;
	cSDL* oSDL = new cSDL(&quit, SCREENWIDTH, SCREENHEIGHT);
	SDL_Renderer *renderer;

	Uint32 USER_TIMER = SDL_RegisterEvents(1);
	SDL_Event timer;
	SDL_memset(&timer, 0, sizeof(timer)); /* or SDL_zero(event) */
	timer.type = USER_TIMER;
	timer.user.code = 0;
	timer.user.data1 = NULL;
	timer.user.data2 = NULL;

	Uint32 t = SDL_GetTicks();
	Uint32 t_old = t;
	SDL_Event ev;

	//Setting up everything else
	srand(time(0));

	colony colony1;


	//main loop
	while (!quit){

		oSDL->Begin();

		renderer = oSDL->GetRenderer();
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, NULL);

		colony1.draw(renderer);
		

		

		
		oSDL->End();

		t = SDL_GetTicks();
		if (t > t_old + 50){
			SDL_PushEvent(&timer);
			t_old = t;
			cout << "tick \n";
		}

		while (SDL_PollEvent(&ev)){
			switch (ev.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
				break;
			}
			if (ev.type == USER_TIMER){
				cout << "tock \n";
				colony1.timeStep();
			}
		}
		
		
		

		
	}



	return 0;
}
