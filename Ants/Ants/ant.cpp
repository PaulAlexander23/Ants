#include "ant.h"


ant::ant(){
	position.x = rand() / double(RAND_MAX) * 1280;
	position.y = rand() / double(RAND_MAX) * 800;
	double randa;
	randa = 2 * M_PI * rand() / double(RAND_MAX);
	velocity.x = cos(randa);
	velocity.y = sin(randa);
	yard = 1;
	food = false;
}

ant::ant(short x, short y){
	position.x = x;
	position.y = y;
	double randa;
	randa = 2 * M_PI * rand() / double(RAND_MAX);
	velocity.x = cos(randa);
	velocity.y = sin(randa);
	yard = 1;
	food = false;
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

	if (position.x > 80 && position.y > 80 && position.x > 120 && position.y < 120 && food == false){
		food = true;
	}

	if (position.x > 780 && position.y > 80 && position.x > 820 && position.y < 120 && food == true){
		food = false;
	}

}

void ant::changeVelocity(vector detv){
	vector randv;
	double randa;
	randa = 2 * M_PI * rand() / double(RAND_MAX);
	randv.x = 0.6 * cos(randa);
	randv.y = 0.6 * sin(randa);

	double h = 0.1;
	double w = 0.2;

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

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	return(SDL_RenderFillRect(renderer, &rect));
}