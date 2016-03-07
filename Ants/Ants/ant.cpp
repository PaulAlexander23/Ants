#include "ant.h"


ant::ant(){
	position.x = rand() / double(RAND_MAX) * 1280;
	position.y = rand() / double(RAND_MAX) * 800;
	//direction = 0;
	direction = rand() / double(RAND_MAX) * 2 * M_PI;
	yard = 1;
	food = false;
}

ant::ant(short x, short y){
	position.x = x;
	position.y = y;
	//direction = 0;
	direction = rand() / double(RAND_MAX) * 2 * M_PI;
	yard = 1;
	food = false;
}

void ant::timeStep(vector detv){
	changeDirection(detv);
	move();
}

void ant::move(){
	position.x += yard * cos(direction);
	position.y += yard * sin(direction);

	if (position.x < 0 || position.y < 0 || position.x > 1280 || position.y > 800){
		position.x = 320;
		position.y = 200;
	}

	if (position.x > 1000 && position.y > 100 && position.x > 1100 && position.y < 200 && food == false){
		food = true;
	}

}

void ant::changeDirection(vector detv){
	double deta; //Deterministic angle
	double randa; //Random angle
	randa = rand() / double(RAND_MAX) * 2 * M_PI;

	double h = 1; //

	/*if (detv.x == 0){
		if (detv.y == 0){
			direction = fmod(randa, 2.0 * M_PI);
			return;
		}
		else if (detv.y > 0){
			deta = -M_PI / 2;
		}
		else{
			deta = M_PI / 2;
		}
	}
	else */
	if (detv.x < 0){
		deta = atan((detv.y) / (detv.x)) + M_PI;
	}
	else{
		deta = fmod(atan((detv.y) / (detv.x)), 2 * M_PI);
	}

	//direction = fmod((deta + (randa - M_PI)) / 2, 2 * M_PI);

	direction = fmod(direction + (deta-direction)*h, 2 * M_PI);
}

int ant::draw(SDL_Renderer *renderer){
	SDL_Rect rect;
	rect.x = int(position.x - 1);
	rect.y = int(position.y - 1);
	rect.w = 2;
	rect.h = 2;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	return(SDL_RenderFillRect(renderer, &rect));
}