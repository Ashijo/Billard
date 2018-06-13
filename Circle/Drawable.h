#pragma once
#include <SDL.h>

class Drawable
{
public:
	Drawable();


	virtual ~Drawable();
	virtual void Draw(SDL_Renderer* render) = 0;
};

