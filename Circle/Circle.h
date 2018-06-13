#pragma once
#include "Drawable.h"
#include "Point.h"
#include <cmath>
#include "Constantes.h"

class Circle : Drawable
{
public:
	Circle();
	~Circle();
	Circle(Point center, double rayon);
	void Draw(SDL_Renderer* render) override;
	void updatePos(double x, double y);
	Point getPos();
	void getPos(double* x, double* y);

protected: 
	Point pos;
	double rayon;

};

