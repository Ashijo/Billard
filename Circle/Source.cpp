#include <iostream>
#include "Game.h"

using namespace std;


int main(int argc, char** e) {
	Game* game = new Game();

	game->start();
	game->run();
	game->close();

	game->~Game();

	return 0;
}

