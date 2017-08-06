#include "scent.h"

scent::scent()
{
	for (int i = 0; i < 320; i++){
		for (int j = 0; j < 200; j++){
			grid[i][j] = 0;
			y[j] = 4 * j;
		}
		x[i] = 4 * i;
	}
}

//Alternate
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

scent::~scent()
{
}

void scent::diffuse(float ts, float lambda){
	float d2grid[320][200];
	for (int i = 1; i < 320-1; i++){
		for (int j = 1; j < 200-1; j++){
			d2grid[i][j] = (4 * grid[i][j] - grid[i - 1][j] - grid[i + 1][j] - grid[i][j-1] - grid[i][j+1])/((x[1]-x[0])*(y[1]-y[0]));
		}
	}

	for (int i = 1; i < 320 - 1; i++){
		for (int j = 1; j < 200 - 1; j++){
			grid[i][j] -= lambda * ts * d2grid[i][j];
		}
	}
}


int scent::find_cell(int z, bool horizontal){
    int i = 0;    
    if(horizontal){
        while (z > x[i] && i < 320){
            i++;
        } i--;
    }
    else{
        while (z > y[i] && i < 200){
            i++;
        } i--;
    }
    return i;
}


void scent::add(vector position){
	grid[find_cell(position.x,true)][find_cell(position.y,false)] += 1;
}

vector scent::grad(vector position){
    int i = find_cell(position.x, true);
    int j = find_cell(position.y, false);

	vector detv;

    if (i == 1){
        detv.x = 1;
        detv.y = 0;
    }
    else if (j == 1){
        detv.x = 0;
        detv.y = 1;
    }
	else if (i == 320){
		detv.x = -1;
		detv.y = 0;
	}
	else if (j == 200){
		detv.x = 0;
		detv.y = -1;
	}
	else{
		detv.x = (grid[i + 1][j] - grid[i][j]) / (x[1] - x[0]);
		detv.y = (grid[i][j + 1] - grid[i][j]) / (y[1] - y[0]);
	}
	return detv;
}

int scent::draw(SDL_Renderer *renderer){
	SDL_Rect rect;
	rect.h = 4;
	rect.w = 4;
	
	float max = 0;
	float min = 7e37;

	/*for (int i = 0; i < 320; i++){
		for (int j = 0; j < 200; j++){
			if (max < grid[i][j]){
				max = grid[i][j];
			}
			if (min > grid[i][j])
				min = grid[i][j];
		}
	}*/

	//printf("Max: %g Min: %g \n", max, min);

	int out = 0;
	for (int i = 0; i < 320; i++){
		for (int j = 0; j < 200; j++){
			rect.x = x[i] - 2;
			rect.y = y[j] - 2;
			//SDL_SetRenderDrawColor(renderer, int(255.0 * ((grid[i][j] - min) / (max - min))), int(255.0 * ((grid[i][j] - min) / (max - min))), int(255.0 * ((grid[i][j] - min) / (max - min))), 255);
            SDL_SetRenderDrawColor(renderer, int(255-grid[i][j]), int(255-grid[i][j]), int(255-grid[i][j]), 255);
			out = SDL_RenderFillRect(renderer,&rect);
			if (out == -1){
				return(out);
			}
		}
	}
	return(out);
}
