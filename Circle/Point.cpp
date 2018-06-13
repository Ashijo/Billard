#include "Point.h"


Point::Point()
{
	x = 0;
	y = 0;
}


Point::~Point()
{
}

Point::Point(double x, double y){
	this->x = x;
	this->y = y;
}