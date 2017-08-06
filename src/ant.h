#pragma once
#include "main.h"

class ant
{
private:
	double direction; // 0 <= direction < 2*pi
	short yard;
public:
	bool food;
	vector position;
	vector velocity;
	ant();
	ant(short x, short y);
	void time_step(vector detv);
	void change_velocity(vector detv);
	void move();
	int draw(SDL_Renderer *renderer);
};
