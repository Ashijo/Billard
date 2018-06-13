#include "Ball.h"


Ball::Ball()
{
}


Ball::~Ball()
{
}

Ball::Ball(Point pos, double rayon, int number):Circle(pos, rayon){
	this->number = number;
	falled = false;
	mooving = false;
}


void Ball::updatePos(){

	frotement.setVectXY(vitesse.getVect().x * -1 / 75, vitesse.getVect().y * -1 / 75);
	vitesse.setVectXY(vitesse.getVect().x + frotement.getVect().x, vitesse.getVect().y + frotement.getVect().y);

	if (vitesse.getVect().x < EPSILON && vitesse.getVect().x > -EPSILON && vitesse.getVect().y < EPSILON && vitesse.getVect().y > -EPSILON ){
		mooving = false;
	}
	else{
		mooving = true;
	}

	pos.x += vitesse.getVect().x;
	pos.y += vitesse.getVect().y;
}

Point Ball::getPos(){
	return pos;
}


void Ball::setVitesse(Force f){
	vitesse = f;
}

void Ball::setVitesse(Point p){
	vitesse.setVectXY(p);
}

void Ball::setVitesse(double x, double y){
	vitesse.setVectXY(x, y);
}

Force Ball::getVitesse(){
	return vitesse;
}

void Ball::addVitesse(Force f){
	Point v = vitesse.getVect();
	v.x += f.getVect().x;
	v.y += f.getVect().y;
	vitesse.setVectXY(v);

}

int Ball::getNumber(){
	return this->number;
}

bool Ball::isFalled(){
	return falled;
}

bool Ball::isMooving(){
	return mooving;
}


void Ball::fall(){
	falled = true;
}

void Ball::setPos(double x, double y){
	pos.x = x;
	pos.y = y;
	setVitesse(0, 0);
};