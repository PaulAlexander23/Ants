#pragma once
#include "Header1.h"
#include "ant.h"
#include "diffusionGrid.h"

class colony
{
public:
	colony();
	void timeStep();
	int draw(SDL_Renderer *renderer);
	~colony();

private:
	ant ants[100];
	diffusionGrid grids[2];

	double x[320];
	double y[200];


};

