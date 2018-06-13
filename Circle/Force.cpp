#include "Force.h"


Force::Force()
{
	vect.x = 0;
	vect.y = 0;
}


Force::~Force()
{
}


Force::Force(Point vect){
	this->vect = vect;
};

void Force::setVectXY(Point p){
	this->vect = p;
}

void Force::setVectXY(double x, double y){
	vect.x = x;
	vect.y = y;
}

Point Force::getVect(){
	return vect;
};


Force::Force(Point A, Point B){
	vect.x = B.x - A.x;
	vect.y = B.y - A.y;
}

Force::Force(double x, double y){
	vect.x = x;
	vect.y = y;
}

Force Force::getNewByNeutral(double newNorm){
	double norm = sqrt((vect.x * vect.x) + (vect.y * vect.y));

	Force f(vect.x / norm * newNorm, vect.y / norm * newNorm);
	
	return f;
}