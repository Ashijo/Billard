#pragma once
#include <vector>
#include "Point.h"
#include "Force.h"
#include "Ball.h"
#include "Field.h"
#include "Game.h"

class Game;
class ColliderManager
{
public:
	ColliderManager();
	~ColliderManager();
	ColliderManager(Field* field, Game* ctx);

	void update();
	void addBall(Ball* ball);
	void killBall(int number);

private:
	std::vector <Ball*> balls;
	std::vector <Circle*> holes;
	SDL_Rect field;
	Game *ctx = NULL;
};

