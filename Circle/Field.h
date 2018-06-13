#pragma once
#include <SDL.h>
#include "Constantes.h"
#include "Drawable.h"
#include "Circle.h"
#include <vector>

class Field : Drawable
{
public:
	Field();
	~Field();
	void Draw(SDL_Renderer* render) override;
	std::vector<Circle*> getHoles();
	SDL_Rect getField();


private:
	SDL_Rect grass, top, bot, right, left; //borders & game field
	Circle *topLeft, *midLeft, *botLeft, *topRight, *midRight, *botRight; //holes
	Circle *cornerTopLeft, *cornerTopRight, *cornerBotLeft, *cornerBotRight; ////corner rounders
	Point centerHalfCircle;


};

