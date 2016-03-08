#pragma once
#include "Header1.h"

class ant
{
private:
	double direction; // 0 =< direction < 2*pi
	short yard;
public:
	bool food;
	vector position;
	vector velocity;
	ant();
	ant(short x, short y);
	void timeStep(vector detv);
	void changeVelocity(vector detv);
	void move();
	int draw(SDL_Renderer *renderer);
};

