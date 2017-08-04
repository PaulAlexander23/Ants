#include "Header1.h"
#include "diffusionGrid.h"


diffusionGrid::diffusionGrid()
{
	for (int i = 0; i < 320; i++){
		for (int j = 0; j < 200; j++){
			grid[i][j] = 10;
			y[j] = 4 * j;
		}
		x[i] = 4 * i;
	}
}

void diffusionGrid::Diffuse(){
	float tempgrid[320][200];
	for (int i = 1; i < 320-1; i++){
		for (int j = 1; j < 200-1; j++){
			tempgrid[i][j] = -grid[i - 1][j] + 2 * grid[i][j] - grid[i + 1][j] - grid[i][j-1] + 2 * grid[i][j] - grid[i][j+1];
		}
	}


	for (int i = 1; i < 320 - 1; i++){
		for (int j = 1; j < 200 - 1; j++){
			grid[i][j] += tempgrid[i][j];
			grid[i][j] = grid[i][j] / 100;
		}
	}

}

void diffusionGrid::Add(int i, int j){

	grid[i][j] += 1;

}

vector diffusionGrid::Grad(int i, int j){
	vector detv;
	if (i == 320){
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

int diffusionGrid::draw(SDL_Renderer *renderer){
	SDL_Rect rect;
	rect.h = 4;
	rect.w = 4;
	
	float max = 0;
	float min = 7e37;

	for (int i = 0; i < 320; i++){
		for (int j = 0; j < 200; j++){
			if (max < grid[i][j]){
				max = grid[i][j];
			}
			if (min > grid[i][j])
				min = grid[i][j];
		}
	}

	//printf("Max: %g Min: %g \n", max, min);

	int out = 0;
	for (int i = 0; i < 320; i++){
		for (int j = 0; j < 200; j++){
			rect.x = x[i] - 2;
			rect.y = y[j] - 2;
			SDL_SetRenderDrawColor(renderer, int(255.0 * ((grid[i][j] - min) / (max - min))), 255, 255, 255);
			out = SDL_RenderFillRect(renderer,&rect);
			if (out == -1){
				return(out);
			}

		}
	}

	return(out);
}

diffusionGrid::~diffusionGrid()
{
}
