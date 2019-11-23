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
	

	muerte = game->OnCollisionEnter(&getDestRect());
	if (muerte)
	{
		//game->RestaPuntos();
		instMuerte = SDL_GetTicks();
	}

	if (i >= 0 && i <= WIN_WIDTH - 60 && j >= 0 && j <= WIN_HEIGHT - 60 && !muerte) {
		ArrowsGameObject::update();
		//mientras este viva y en los limites cada cierto tiempo le cambiamos la direccion?
	}

	if (SDL_GetTicks() < instMuerte + TIME_Animation && vuelo < 9) {
		vuelo++;
	}
	if (vuelo >= 9)
	{
		//se cae hacia abajo y es eliminada
		velocity = Vector2D(velocity.getX() * 0, 2);
		//aqui tiene que pasar cierto tiempo y despues ser eliminada
		game->KillObject(this->i);
	}
}