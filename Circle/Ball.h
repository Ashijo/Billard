#pragma once
#include "Point.h"
#include "Force.h"
#include <vector>
#include "Circle.h"
#include "Drawable.h"

class Ball : public Circle
{
public:
	Ball();
	~Ball();
	Ball(Point pos, double rayon, int number);

	void updatePos();
	Point getPos();
	int getNumber();
	void setPos(double x, double y);

	void setVitesse(Force f);
	void setVitesse(Point p);
	void setVitesse(double x, double y);
	void addVitesse(Force f);

	Force getVitesse();
	bool isFalled();
	bool isMooving();
	void fall();

private:
	bool mooving;
	bool falled;
	int number;
	Force vitesse;
	Force frotement;
};

