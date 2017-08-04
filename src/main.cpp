//Simple ants

#include "main.h"
#include "cSDL.h"
#include "ant.h"
#include "colony.h"
#include "Timer.h"

using namespace std;

Uint32 my_callbackfunc(Uint32 interval, void *param);

int main(int argc, char **argv){

	//Setting up SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	int SCREENHEIGHT = 800;
	int SCREENWIDTH = 1280;

	bool quit = false;
	cSDL* oSDL = new cSDL(&quit, SCREENWIDTH, SCREENHEIGHT);
	SDL_Renderer *renderer;

/*	const Uint32 USER_TIMER = SDL_RegisterEvents(1);
	SDL_Event timer;
	SDL_memset(&timer, 0, sizeof(timer)); /* or SDL_zero(event) *
	timer.type = USER_TIMER;
	timer.user.code = 0;
	timer.user.data1 = NULL;
	timer.user.data2 = NULL;
	Uint32 t = SDL_GetTicks();
	Uint32 t_old = t;*/

    Timer timer1(100);
    SDL_Event ev;

	//Setting up everything else
	srand(time(0));

    struct Keys
    {
        bool SPACE;
    };

    Keys keyPressed;
    keyPressed.SPACE = false;

	colony colony1;

	//main loop
	while (!quit){

        /*t = SDL_GetTicks();
		if (t > t_old + 50){
            cout << "t \n";
			SDL_PushEvent(&timer);
			t_old = t;
			cout << "tick \n";
		}*/


	    while(SDL_PollEvent(&ev))
        {
		    switch(ev.type)
            {
		    case SDL_QUIT:
			    quit = true;
			    break;
		    case SDL_MOUSEBUTTONDOWN:
    		    break;
            case SDL_KEYDOWN:
                switch(ev.key.keysym.sym)
                {
                case SDLK_SPACE:
                    cout<<"Space Bar Down"<<endl;
                    if(keyPressed.SPACE == false)
                    {
                        timer1.ToggleTimer();
                        keyPressed.SPACE = true;
                    }
                }
            case SDL_KEYUP:
                switch(ev.key.keysym.sym)
                {
                case SDLK_SPACE:
                    cout<<"Space Bar Up"<<endl;
                    if(keyPressed.SPACE == true)
                    {
                        keyPressed.SPACE = false;
                    }
                }
            case SDL_USEREVENT:
                colony1.timeStep();
                break;
		    }
	    }
        oSDL->Begin();
        renderer = oSDL->GetRenderer();
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, NULL);
        colony1.draw(renderer);
        oSDL->End();
	}

	return 0;
}

Uint32 my_callbackfunc(Uint32 interval, void *param)
{
    SDL_Event event;
    SDL_UserEvent userevent;

    /* In this example, our callback pushes an SDL_USEREVENT event
    into the queue, and causes our callback to be called again at the
    same interval: */

    userevent.type = SDL_USEREVENT;
    userevent.code = 0;
    userevent.data1 = NULL;
    userevent.data2 = NULL;

    event.type = SDL_USEREVENT;
    event.user = userevent;

    SDL_PushEvent(&event);
    return(interval);
}
