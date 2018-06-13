#pragma once
#include <SDL.h>
#include <iostream>
#include "Constantes.h"
#include "Point.h"
#include "Force.h"
#include "Field.h"
#include "Ball.h"
#include "ColliderManager.h"

class ColliderManager;
class Game
{
public:
	Game();
	~Game();
	void start();
	void run();
	void close();

	void fallingWhite();
	void fallingBlack();
	void fallingBalls(int number);

private:
	bool inGame;
	void gameOver();

	int cptYellow = 0;
	int cptRed = 0;

	SDL_Event eventP;
	SDL_Window* window = NULL;
	SDL_Renderer* render = NULL;

	const Uint8* states;

	std::vector<Ball*> balls;

	bool playable;

	void event();
	void updateModel();
	void clean();
	void draw();

	ColliderManager* moteur = NULL;

	Field* field = NULL;
	Ball* white = NULL;
	Ball* black = NULL;

	double xO = -1;
	double yO, xV, yV;

};

