#include "Field.h"


Field::Field()
{
	grass.w = FIELD_HEIGHT / 2;
	grass.h = FIELD_HEIGHT;
	grass.x = (WIDTH_SCREEN / 2) - (FIELD_HEIGHT / 4);
	grass.y = (HEIGHT_SCREEN / 2) - (FIELD_HEIGHT / 2);

	top.w = FIELD_HEIGHT / 2;
	top.h = BORDER_WIDTH;
	top.x = (WIDTH_SCREEN / 2) - (FIELD_HEIGHT / 4);
	top.y = (HEIGHT_SCREEN / 2) - (FIELD_HEIGHT / 2) - BORDER_WIDTH;

	left.w = BORDER_WIDTH;
	left.h = FIELD_HEIGHT;
	left.x = (WIDTH_SCREEN / 2) - (FIELD_HEIGHT / 4) - BORDER_WIDTH;
	left.y = (HEIGHT_SCREEN / 2) - (FIELD_HEIGHT / 2);

	right.w = BORDER_WIDTH;
	right.h = FIELD_HEIGHT;
	right.x = (WIDTH_SCREEN / 2) + (FIELD_HEIGHT / 4);
	right.y = (HEIGHT_SCREEN / 2) - (FIELD_HEIGHT / 2);

	bot.w = FIELD_HEIGHT / 2;
	bot.h = BORDER_WIDTH;
	bot.x = (WIDTH_SCREEN / 2) - (FIELD_HEIGHT / 4);
	bot.y = (HEIGHT_SCREEN / 2) + (FIELD_HEIGHT / 2);


	Point center;
	center.x = (WIDTH_SCREEN / 2) - (FIELD_HEIGHT / 4);
	center.y = (HEIGHT_SCREEN / 2) - (FIELD_HEIGHT / 2);
	topLeft = new Circle(center, HOLES_SIZE);
	cornerTopLeft = new Circle(center, 19);


	center.x = (WIDTH_SCREEN / 2) + (FIELD_HEIGHT / 4);
	topRight = new Circle(center, HOLES_SIZE);
	cornerTopRight = new Circle(center, 19);


	center.y = (HEIGHT_SCREEN / 2) + (FIELD_HEIGHT / 2);
	botRight = new Circle(center, HOLES_SIZE);
	cornerBotRight = new Circle(center, 19);

	center.x = (WIDTH_SCREEN / 2) - (FIELD_HEIGHT / 4);
	botLeft = new Circle(center, HOLES_SIZE);
	cornerBotLeft = new Circle(center, 19);

	center.y = HEIGHT_SCREEN / 2;
	midLeft = new Circle(center, HOLES_SIZE);

	center.x = (WIDTH_SCREEN / 2) + (FIELD_HEIGHT / 4);
	midRight = new Circle(center, HOLES_SIZE);


	centerHalfCircle.x = WIDTH_SCREEN / 2;
	centerHalfCircle.y = (HEIGHT_SCREEN / 2) + (FIELD_HEIGHT / 4);


}


Field::~Field()
{
	topLeft->~Circle();
	cornerTopLeft->~Circle();

	topRight->~Circle();
	cornerTopRight->~Circle();

	botRight->~Circle();
	cornerBotRight->~Circle();

	botLeft->~Circle();
	cornerBotLeft->~Circle();

	midLeft->~Circle();
	midRight->~Circle();

}


void Field::Draw(SDL_Renderer* render){
	
	

	SDL_SetRenderDrawColor(render, 128, 0, 0, 255);
	SDL_RenderFillRect(render, &top);
	SDL_RenderFillRect(render, &left);
	SDL_RenderFillRect(render, &right);
	SDL_RenderFillRect(render, &bot);
	cornerTopLeft->Draw(render);
	cornerTopRight->Draw(render);
	cornerBotRight->Draw(render);
	cornerBotLeft->Draw(render);



	SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
	SDL_RenderFillRect(render, &grass);

	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	topLeft->Draw(render);
	topRight->Draw(render);
	botRight->Draw(render);
	botLeft->Draw(render);
	midRight->Draw(render);
	midLeft->Draw(render);

	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	SDL_RenderDrawLine(render, (WIDTH_SCREEN / 2) - (FIELD_HEIGHT / 4), (HEIGHT_SCREEN / 2) + (FIELD_HEIGHT / 4), (WIDTH_SCREEN / 2) + (FIELD_HEIGHT / 4) - 1, (HEIGHT_SCREEN / 2) + (FIELD_HEIGHT / 4));

	for (int i = 0; i < 180; i++){
		SDL_RenderDrawPoint(render, 40 * cos(i * PI / 180) + centerHalfCircle.x, 40 * sin(i * PI / 180) + centerHalfCircle.y);
	}


};


std::vector<Circle*> Field::getHoles(){
	std::vector<Circle*> holes;

	holes.push_back(topLeft);
	holes.push_back(topRight);
	holes.push_back(midLeft);
	holes.push_back(midRight);
	holes.push_back(botLeft);
	holes.push_back(botRight);

	holes.shrink_to_fit();


	return holes;
};

SDL_Rect Field::getField(){
	return this->grass;
};