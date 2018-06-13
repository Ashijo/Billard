#include "Game.h"


Game::Game()
{
	inGame = true;
	playable = true;
	field = new Field();

	Point pos;
	
	pos.x = WIDTH_SCREEN / 2;
	pos.y = HEIGHT_SCREEN / 2 + FIELD_HEIGHT / 4;
	white = new Ball(pos, BALLS_SIZE, 0);

	pos.x = WIDTH_SCREEN / 2;
	pos.y = HEIGHT_SCREEN / 2 - FIELD_HEIGHT / 3;
	black = new Ball(pos, BALLS_SIZE, 8);



	//reds
	pos.x = (WIDTH_SCREEN / 2) - (FIELD_HEIGHT / 6) + BALLS_SIZE * 2.1;
	pos.y = (HEIGHT_SCREEN / 2) - (FIELD_HEIGHT / 2) + BALLS_SIZE * 3.1;
	Ball* red1 = new Ball(pos, BALLS_SIZE, 1);
	pos.x += BALLS_SIZE * 2.5;
	Ball* red2 = new Ball(pos, BALLS_SIZE, 3);
	pos.x += BALLS_SIZE * 2.5;
	Ball* red3 = new Ball(pos, BALLS_SIZE, 5);
	pos.x += BALLS_SIZE * 2.5;
	Ball* red4 = new Ball(pos, BALLS_SIZE, 9);
	pos.x += BALLS_SIZE * 2.5;
	Ball* red5 = new Ball(pos, BALLS_SIZE, 11);
	pos.x += BALLS_SIZE * 2.5;
	Ball* red6 = new Ball(pos, BALLS_SIZE, 13);
	pos.x += BALLS_SIZE * 2.5;
	Ball* red7 = new Ball(pos, BALLS_SIZE, 15);


	//yellows
	pos.x = (WIDTH_SCREEN / 2) - (FIELD_HEIGHT / 6) + BALLS_SIZE * 2.1;
	pos.y = (HEIGHT_SCREEN / 2) - (FIELD_HEIGHT / 2) + BALLS_SIZE * 6;
	Ball*  yellow1 = new Ball(pos, BALLS_SIZE, 2);
	pos.x += BALLS_SIZE * 2.5;
	Ball*  yellow2 = new Ball(pos, BALLS_SIZE, 4);
	pos.x += BALLS_SIZE * 2.5;
	Ball*  yellow3 = new Ball(pos, BALLS_SIZE, 6);
	pos.x += BALLS_SIZE * 2.5;
	Ball*  yellow4 = new Ball(pos, BALLS_SIZE, 10);
	pos.x += BALLS_SIZE * 2.5;
	Ball*  yellow5 = new Ball(pos, BALLS_SIZE, 12);
	pos.x += BALLS_SIZE * 2.5;
	Ball*  yellow6 = new Ball(pos, BALLS_SIZE, 14);
	pos.x += BALLS_SIZE * 2.5;
	Ball*  yellow7 = new Ball(pos, BALLS_SIZE, 16);

	balls.push_back(red1);
	balls.push_back(red2);
	balls.push_back(red3);
	balls.push_back(red4);
	balls.push_back(red5);
	balls.push_back(red6);
	balls.push_back(red7);

	balls.push_back(yellow1);
	balls.push_back(yellow2);
	balls.push_back(yellow3);
	balls.push_back(yellow4);
	balls.push_back(yellow5);
	balls.push_back(yellow6);
	balls.push_back(yellow7);


	moteur = new ColliderManager(field, this);
	moteur->addBall(white);
	moteur->addBall(black);
	moteur->addBall(red1);
	moteur->addBall(red2);
	moteur->addBall(red3);
	moteur->addBall(red4);
	moteur->addBall(red5);
	moteur->addBall(red6);
	moteur->addBall(red7);
	moteur->addBall(yellow1);
	moteur->addBall(yellow2);
	moteur->addBall(yellow3);
	moteur->addBall(yellow4);
	moteur->addBall(yellow5);
	moteur->addBall(yellow6);
	moteur->addBall(yellow7);



	//Force f(0, -12);
	//white->setVitesse(f);
}


Game::~Game()
{
	field->~Field();
	white->~Ball();
	black->~Ball();
	moteur->~ColliderManager();
}


void Game::start(){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(WIDTH_SCREEN, HEIGHT_SCREEN, SDL_WINDOW_SHOWN, &window, &render);
}


void Game::run(){

	while (inGame){
		Uint32 start = SDL_GetTicks();
	
		event();
		updateModel();
		clean();
		draw();

		Uint32 end = SDL_GetTicks();
		if (end - start < 1000 / FPS){
			SDL_Delay((1000 / FPS) - (end - start));
		}
	}
}

void Game::close(){
	SDL_Quit();
}


void Game::event(){
	int only_one;
	only_one = SDL_PollEvent(&eventP);
	states = SDL_GetKeyboardState(NULL);
	int xM, yM;
	Uint32 mouse;

	mouse = SDL_GetMouseState(&xM, &yM);


	

	if (eventP.type == SDL_QUIT || states[SDL_SCANCODE_ESCAPE]){
		inGame = false;
	}
	if (eventP.type == SDL_MOUSEBUTTONDOWN && only_one == 1 && playable){

		xO = white->getPos().x;
		yO = white->getPos().y;
	}
	if (eventP.type == SDL_MOUSEBUTTONUP && only_one == 1 && playable){
		double xF = (xO - xV) / 10;
		double yF = (yO - yV) / 10;
		Force f(xF, yF);
		white->addVitesse(f);

	}
	if (mouse == 1){
		xV = xM;
		yV = yM;
	}

}

void Game::updateModel(){

	playable = true;


	white->updatePos();
	black->updatePos();

	if (white->isMooving() || black->isMooving()){
		playable = false;
	}

	for (int i = 0; i < balls.size(); i++)
	{

		balls[i]->updatePos();
		if (balls[i]->isMooving())
			playable = false;
	}

	moteur->update();
}

void Game::clean(){
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	SDL_RenderClear(render);

}

void Game::draw(){
	
	field->Draw(render);
	
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	white->Draw(render);

	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	black->Draw(render);

	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i]->getNumber() % 2 == 0){
			//yellow
			SDL_SetRenderDrawColor(render, 255, 205, 0, 255);
		}
		else{
			//red
			SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
		}

		balls[i]->Draw(render);
	}

	if (xO != -1 && playable){
		SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
		SDL_RenderDrawLine(render, xO, yO, xV, yV);
	}

	SDL_RenderPresent(render);

}


void Game::fallingWhite(){
	white->setPos(WIDTH_SCREEN / 2, HEIGHT_SCREEN / 2 + FIELD_HEIGHT / 4);
}

void Game::fallingBlack(){
	
	gameOver();
}


void Game::fallingBalls(int number){
	
	if (number % 2 == 0){
		cptYellow++;
	}
	else{
		cptRed++;
	}

	int it = 0;
	bool breaker = true;
	std::vector<Ball*>::iterator i = balls.begin();


	while (breaker && it < balls.size() )
	{

		if (balls[it]->getNumber() == number){
			breaker = false;
		}
		else{
			i++;
			it++;
		}
	}
	moteur->killBall(number);
	balls.erase(i);
	balls.shrink_to_fit();

	std::cout << "__________________________________________" << std::endl<<std::endl;
	std::cout << "Points jaunes : " << cptYellow << std::endl;
	std::cout << "Points rouges : " << cptRed<< std::endl;


}

void Game::gameOver(){
	inGame = false;
}