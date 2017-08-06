#pragma once
#include "main.h"

class scent
{
public:
	scent();
    ~scent();
	void diffuse(float ts, float lambda);
	void add(vector position);
	vector grad(vector position);
	int draw(SDL_Renderer *renderer);
    int find_cell(int z, bool horizontal);


private:
    float grid[320][200];
    double x[320];
    double y[200];
};

