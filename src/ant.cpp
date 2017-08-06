#include "ant.h"


ant::ant(){
	position.x = 400;
	position.y = 400;
	/*position.x = rand() / double(RAND_MAX) * 1280;
	position.y = rand() / double(RAND_MAX) * 800;*/
	double randa;
	randa = 2 * M_PI * rand() / double(RAND_MAX);
	velocity.x = cos(randa);
	velocity.y = sin(randa);
	yard = 1;
	food = 0;
    //food = rand() % 2;
}

ant::ant(short x, short y){
	position.x = x;
	position.y = y;
	ant();
}

void ant::time_step(vector detv){
	change_velocity(detv);
	move();
}

void ant::move(){
	position.x += yard * velocity.x;
	position.y += yard * velocity.y;

	if (position.x < 0 || position.y < 0 || position.x > 1280 || position.y > 800){
		position.x = 320;
		position.y = 200;
	}
}

void ant::change_velocity(vector detv){
	vector randv;
	double randa;
	randa = 2 * M_PI * rand() / double(RAND_MAX);
	randv.x = 0.6 * cos(randa);
	randv.y = 0.6 * sin(randa);

	double h = 1;
	double w = 0.1;

	velocity.x += h * w * detv.x + sqrt(h) * (1 - w) * randv.x;
	velocity.y += h * w * detv.y + sqrt(h) * (1 - w) * randv.y;

	double norm;
	norm = sqrt(pow(velocity.x, 2) + pow(velocity.y, 2));

	velocity.x = velocity.x / norm;
	velocity.y = velocity.y / norm;

}

int ant::draw(SDL_Renderer *renderer){
	SDL_Rect rect;
	rect.x = int(position.x - 1);
	rect.y = int(position.y - 1);
	rect.w = 2;
	rect.h = 2;

    if(food){
        SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
    }
    else{
        SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
    }

	return(SDL_RenderFillRect(renderer, &rect));
}
