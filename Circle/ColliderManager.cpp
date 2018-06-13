#include "ColliderManager.h"


ColliderManager::ColliderManager()
{
}


ColliderManager::~ColliderManager()
{
}

ColliderManager::ColliderManager(Field* field, Game* ctx){

	holes = field->getHoles();
	this->field = field->getField();
	this->ctx = ctx;
}

void ColliderManager::addBall(Ball* ball){
	balls.push_back(ball);
	balls.shrink_to_fit();
}

void ColliderManager::killBall(int number){

	int it = 0;
	bool breaker = true;
	std::vector<Ball*>::iterator i = balls.begin();


	while (breaker && it < balls.size())
	{

		if (balls[it]->getNumber() == number){
			breaker = false;
		}
		else{
			i++;
			it++;
		}
	}
	balls.erase(i);
	balls.shrink_to_fit();

}

void ColliderManager::update(){
	//energie cynetique + qty de mo9uvement

	for (size_t i = 0; i < balls.size(); i++)
	{
		Point pos = balls[i]->getPos();

		if (pos.y - BALLS_SIZE < field.y || pos.y + BALLS_SIZE > field.y + field.h) {
			
			Force f = balls[i]->getVitesse();
			f.setVectXY(f.getVect().x, f.getVect().y * -1);

			balls[i]->setVitesse(f);

		}

		if (pos.x - BALLS_SIZE < field.x || pos.x + BALLS_SIZE > field.x + field.w) {

			Force f = balls[i]->getVitesse();
			f.setVectXY(f.getVect().x * -1, f.getVect().y );

			balls[i]->setVitesse(f);

		}


		for (size_t j = i+1; j < balls.size(); j++)
		{
			Point posB2 = balls[j]->getPos();
			int distXC = pos.x - posB2.x;
			distXC *= distXC;

			int distYC = pos.y - posB2.y;
			distYC *= distYC;

			int distNC = distYC + distXC;

			if (distNC <= pow(BALLS_SIZE*2,2)){

				Force vecteurAB(pos, posB2);
				Force vecteurBA(posB2, pos);
				Force vitesseA(balls[i]->getVitesse());
				Force vitesseB(balls[j]->getVitesse());


				double produitScalaireA = (vecteurAB.getVect().x * vitesseA.getVect().x) + (vecteurAB.getVect().y * vitesseA.getVect().y);
				double produitScalaireB = (vecteurBA.getVect().x * vitesseB.getVect().x) + (vecteurBA.getVect().y * vitesseB.getVect().y);

				double lA = produitScalaireA / sqrt((vecteurAB.getVect().x*vecteurAB.getVect().x) + (vecteurAB.getVect().y*vecteurAB.getVect().y));
				double lB = produitScalaireB / sqrt((vecteurBA.getVect().x*vecteurBA.getVect().x) + (vecteurBA.getVect().y*vecteurBA.getVect().y));

				//Methode creant un nouveau vecteur a partir de la direction et le sens un existant d'un vecteur uet une nouvelle norme passé en paramettre
				Force impactA = vecteurAB.getNewByNeutral(lA);
				Force impactB = vecteurBA.getNewByNeutral(lB);

				balls[i]->addVitesse(impactB);
				balls[j]->addVitesse(impactA);

				impactA.setVectXY(impactA.getVect().x * -1, impactA.getVect().y * -1);
				impactB.setVectXY(impactB.getVect().x * -1, impactB.getVect().y * -1);

				balls[i]->addVitesse(impactA);
				balls[j]->addVitesse(impactB);

			}
		}


		for (size_t j = 0; j < holes.size(); j++)
		{
			
			if (pos.x >= holes[j]->getPos().x - HOLES_SIZE && pos.x <= holes[j]->getPos().x + HOLES_SIZE && pos.y >= holes[j]->getPos().y - HOLES_SIZE && pos.y <= holes[j]->getPos().y + HOLES_SIZE){
			
				if (balls[i]->getNumber() == 0){
					ctx->fallingWhite();
				}
				else if (balls[i]->getNumber() == 8){
					ctx->fallingBlack();
				}
				else{
					ctx->fallingBalls(balls[i]->getNumber());
				}

			
			}


		}

	}
}



