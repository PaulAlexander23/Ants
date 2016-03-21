#include "ant.h"


ant::ant(){
	position.x = rand() / double(RAND_MAX) * 1280;
	position.y = rand() / double(RAND_MAX) * 800;
	double randa;
	randa = 2 * M_PI * rand() / double(RAND_MAX);
	velocity.x = cos(randa);
	velocity.y = sin(randa);
	yard = 1;
	food = rand() % 2;
}

ant::ant(short x, short y){
	position.x = x;
	position.y = y;
	double randa;
	randa = 2 * M_PI * rand() / double(RAND_MAX);
	velocity.x = cos(randa);
	velocity.y = sin(randa);
	yard = 1;
	food = rand() % 2;
}

void ant::timeStep(vector detv){
	changeVelocity(detv);
	move();
}

void ant::move(){
	position.x += yard * velocity.x;
	position.y += yard * velocity.y;

	if (position.x < 0 || position.y < 0 || position.x > 1280 || position.y > 800){
		position.x = 320;
		position.y = 200;
	}

	switch (food)
	{
	case true:
		if (position.x > 0 && position.y > 520 && position.x < 280 && position.y < 800){
			food = false;
		}
		break;
	case false:
		if (position.x > 1000 && position.y > 120 && position.x < 1160 && position.y < 280){
			food = true;
		}
		break;
	}

}

void ant::changeVelocity(vector detv){
	vector randv;
	double randa;
	randa = 2 * M_PI * rand() / double(RAND_MAX);
	randv.x = 0.6 * cos(randa);
	randv.y = 0.6 * sin(randa);

	double h = 1;
	double w = 0.5;

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

	switch (food)
	{
	case true:
		SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
		break;
	case false:
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		break;
	}

	return(SDL_RenderFillRect(renderer, &rect));
}