#include "Header1.h"
#include "diffusionGrid.h"


diffusionGrid::diffusionGrid()
{
	for (int i = 0; i < 320; i++){
		for (int j = 0; j < 200; j++){
			grid[i][j] = 0;
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
			grid[i][j] = tempgrid[i][j];
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


diffusionGrid::~diffusionGrid()
{
}
