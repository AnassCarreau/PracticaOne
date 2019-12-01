#include "Butterfly.h"
#include "Game.h"

const int TIME_Animation = 600;

Butterfly::Butterfly(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* butterfly, Game* game):ArrowsGameObject(esqIzq, vel, ancho, alto, butterfly, game){}

void Butterfly::render() {
	SDL_Rect destRect = ArrowsGameObject::getDestRect();
	if (muerte) {
		textura->renderFrame(destRect, mariposon, 0, 0, SDL_FLIP_NONE);
	}
	else {
		textura->renderFrame(destRect, mariposon, vuelo, 0, SDL_FLIP_NONE);
	}
}

void Butterfly::update() {
	double i = pos.getX();
	double j = pos.getY();
	

	if(!muerte)muerte = game->OnCollisionEnter(getCollisionRect(),this->i);
	if (!muerte && vuelo < 9) {
		vuelo++;
		if (vuelo >= 9) {
			vuelo = 0;
		}
	}
	else if (muerte && instMuerte==0)
	{
		instMuerte = SDL_GetTicks();
		game->AddPoints(-5, 0);
		velocity = Vector2D(0, 2);
		
	}
	else if (SDL_GetTicks() > instMuerte + TIME_Animation) {

		game->KillObject(this->i);

	}
	Pong();
	ArrowsGameObject::update();
}

void Butterfly::Pong()
{
	if (pos.getX()<=0 || pos.getX()>=WIN_WIDTH)
	{
		velocity = Vector2D(-velocity.getX(), velocity.getY());
	}
	else if (pos.getY() <= 0 || pos.getY() >= WIN_HEIGHT)
	{
		velocity = Vector2D(velocity.getX(),- velocity.getY());
	}
}

void Butterfly::saveToFile(ofstream& output) {
	output << "Mariposa" <<endl;
	ArrowsGameObject::saveToFile(output);
}

void Butterfly::loadFromFile(ifstream& input) {
	ArrowsGameObject::loadFromFile(input);
}