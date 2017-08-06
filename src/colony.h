#pragma once
#include "main.h"
#include "ant.h"
#include "scent.h"
#include "zone.h"

class colony
{
public:
	colony();
	~colony();
	void time_step(float ts);
	int draw(SDL_Renderer *renderer);

private:
	ant ants[200];
	scent scents[2]; // 0 - home, 1 - food
    zone zones[2]; // 0 - home, 1 - food
};
