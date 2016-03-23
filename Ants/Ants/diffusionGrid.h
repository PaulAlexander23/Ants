#pragma once
class diffusionGrid
{
public:
	float grid[320][200];
	double x[320];
	double y[200];
	

	diffusionGrid();

	void Diffuse();
	void Add(int i, int j);
	vector Grad(int i, int j);

	~diffusionGrid();
};

