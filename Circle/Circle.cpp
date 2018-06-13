#include "Circle.h"


Circle::Circle()
{
}


Circle::~Circle()
{
}

Circle::Circle(Point center, double rayon){
	
	pos = center;
	this->rayon = rayon;
}

void Circle::updatePos(double x, double y){
	pos.x = x;
	pos.y = y;
}

Point Circle::getPos(){
	return pos;
}

void Circle::getPos(double* x, double* y){
	*x = pos.x;
	*y = pos.y;
}

void Circle::Draw(SDL_Renderer* render){

	for (int i = 0; i < 90; i++){
		SDL_Rect drawer;
		drawer.x = pos.x + (rayon * cos(i * PI / 180));
		drawer.y = pos.y + (rayon * sin(i * PI / 180));
		drawer.h = rayon * sin(i * PI / 180) * 2 * -1;
		drawer.w = rayon * cos(i * PI / 180) * 2 * -1;

		SDL_RenderDrawRect(render, &drawer);
	}


}