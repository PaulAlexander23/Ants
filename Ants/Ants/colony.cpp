#include "colony.h"


colony::colony()
{
	/*for (int i = 0; i < 320; i++){
		for (int j = 0; j < 200; j++){
			grid[0][i][j]  = 500 * exp(-(pow((double(i) - 160), 2) + pow((double(j) - 100), 2)) / 10000);

			grid[1][i][j]  = 1500 * exp(-(pow((double(i) -  20), 2) + pow((double(j) -  20), 2)) / 3000);
			grid[1][i][j] += 1000 * exp(-(pow((double(i) - 260), 2) + pow((double(j) - 160), 2)) / 2000);
			grid[1][i][j] +=  400 * exp(-(pow((double(i) - 200), 2) + pow((double(j) -  20), 2)) / 1000);
			grid[1][i][j] += 1000 * exp(-(pow((double(i) -  20), 2) + pow((double(j) - 140), 2)) / 4000);

			y[j] = 4 * j;
		}
		x[i] = 4 * i;
	}*/

}

void colony::timeStep(){
	vector detv;
	

	detv.x = 0;
	detv.y = 0;
	int j, k = 0;
	for (int i = 0; i < 100; i++){
		j = 0; k = 0;

		while (ants[i].position.x > x[j] && j < 320){
			j++;
		} j--;
		while (ants[i].position.y > y[k] && k < 200){
			k++;
		} k--;

		switch (ants[i].food)
		{
		case true:
			ants[i].timeStep(grids[0].Grad(j, k));
			break;
		case false:
			ants[i].timeStep(grids[1].Grad(j, k));
			break;
		default:
			break;
		}

		ants[i].timeStep(detv);
	}

}

int colony::draw(SDL_Renderer *renderer){
	int out = 0;
	for (int i = 0; i < 100; i++){
		out = ants[i].draw(renderer);
		if (out == -1){
			return(out);
		}
	}
	return(out);
}



colony::~colony()
{
}

