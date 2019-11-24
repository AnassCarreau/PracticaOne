#include "Butterfly.h"
#include "Game.h"

const int TIME_Animation = 600;

Butterfly::Butterfly(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* butterfly, Game* game):ArrowsGameObject(esqIzq, vel, ancho, alto, butterfly, game){}

void Butterfly::render() {
	SDL_Rect* destRect = ArrowsGameObject::getDestRect();
	if (muerte) {
		textura->renderFrame(*destRect, mariposon, 0, 0, SDL_FLIP_NONE);
	}
	else {
		textura->renderFrame(*destRect, mariposon, vuelo, 0, SDL_FLIP_NONE);
	}
}

void Butterfly::update() {
	double i = pos.getX();
	double j = pos.getY();
	

	muerte = game->OnCollisionEnter(getCollisionRect(),this->i);
	if (muerte && instMuerte == 0)
	{
		//game->AddPoints(POINT);
		instMuerte = SDL_GetTicks();
	}
	    Pong();
		ArrowsGameObject::update();
		//mientras este viva y en los limites cada cierto tiempo le cambiamos la direccion?
	

	if (SDL_GetTicks() < instMuerte + TIME_Animation && vuelo < 9 && muerte) {
		vuelo++;
		velocity = Vector2D(0, 2);

	}
	if (vuelo >= 9)
	{
		//se cae hacia abajo y es eliminada
		//aqui tiene que pasar cierto tiempo y despues ser eliminada
		game->KillObject(this->i);
	}
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