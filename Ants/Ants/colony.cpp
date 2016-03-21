#include "colony.h"


colony::colony()
{
	for (int i = 0; i < 320; i++){
		for (int j = 0; j < 200; j++){
			grid[0][i][j] = 1000*exp(-(pow((double(i) -  50), 2) + pow((double(j) - 150), 2))/10000);
			grid[1][i][j] = 1000*exp(-(pow((double(i) - 270), 2) + pow((double(j) -  50), 2))/10000);
			y[j] = 4 * j;
		}
		x[i] = 4 * i;
	}

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


		//cout << "j" << j << ", k" << k << "\n";
		if (j == 320){
			detv.x = -1;
			detv.y = 0;
		}
		else if (k == 200){
			detv.x = 0;
			detv.y = -1;
		}
		else{
			switch (ants[i].food)
			{
			case true:
				detv.x = (grid[0][j + 1][k] - grid[0][j][k]) / (x[1] - x[0]);
				detv.y = (grid[0][j][k + 1] - grid[0][j][k]) / (y[1] - y[0]);
				break;
			case false:
				detv.x = (grid[1][j + 1][k] - grid[1][j][k]) / (x[1] - x[0]);
				detv.y = (grid[1][j][k + 1] - grid[1][j][k]) / (y[1] - y[0]);
				break;
			default:
				break;
			}


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

