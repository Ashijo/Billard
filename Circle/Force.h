#pragma once
#include "Point.h"
#include <cmath>
#include "Constantes.h"

class Force
{
public:
	Force();
	~Force();
	Force(Point vect);
	Force(Point A, Point B);
	Force(double x, double y);
	Point getVect();
	void setVectXY(double x, double y);
	void setVectXY(Point p);
	Force getNewByNeutral(double newNorm);

private:
	Point vect;
};

