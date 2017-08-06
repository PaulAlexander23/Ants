#include "colony.h"

colony::colony()
{
    zones[0].set_rect(300,300,200,200);
    zones[1].set_rect(700,300,200,200);
}


colony::~colony()
{
    
}


void colony::time_step(float ts){
    //first pass - set direction and move
    for (int i = 0; i < 200; i++){
        ants[i].time_step(scents[1-ants[i].food].grad(ants[i].position));
    }

    //second pass - add scent
    for (int i = 0; i < 200; i++){
        if(ants[i].food && zones[0].in(ants[i].position)){
            ants[i].food = 0;
        }
        else if(!ants[i].food && zones[1].in(ants[i].position)){
            ants[i].food = 1;
        }
        scents[ants[i].food].add(ants[i].position);
    }

	scents[0].diffuse(ts, 1);
	scents[1].diffuse(ts, 1);
}


int colony::draw(SDL_Renderer *renderer){
	int out = 0;

	out = scents[0].draw(renderer);
	if (out == -1){
		return(out);
	}

/*
	out = scents[1].draw(renderer);
	if (out == -1){
		return(out);
	}
*/

/*
    SDL_SetRenderDrawColor(renderer,100,0,0,100);
    out = zones[0].draw(renderer);
    if (out == -1){
        return(out);
    }

    SDL_SetRenderDrawColor(renderer,0,100,0,100);
    out = zones[1].draw(renderer);
    if (out == -1){
        return(out);
    }
*/

	for (int i = 0; i < 200; i++){
		out = ants[i].draw(renderer);
		if (out == -1){
			return(out);
		}
	}
	
	return(out);
}
