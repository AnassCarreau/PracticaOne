#include "Butterfly.h"
#include "Game.h"

const int TIME_Animation = 600;

Butterfly::Butterfly(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* butterfly, Game* game):ArrowsGameObject(esqIzq, vel, ancho, alto, butterfly, game){}

void Butterfly::render() {
	SDL_Rect destRect = ArrowsGameObject::getDestRect();
	if (!viva) {
		butterfly->renderFrame(destRect, mariposon, 0, 0, SDL_FLIP_NONE);
	}
	else {
		butterfly->renderFrame(destRect, mariposon, vuelo, 0, SDL_FLIP_NONE);
	}
}

void Butterfly::update() {
	double i = esqIzq.getX();
	double j = esqIzq.getY();
	SDL_Rect* rectButterfly = new SDL_Rect{ (int)esqIzq.getX(),(int)esqIzq.getY(),(int)ancho,(int)alto };

	//viva = game->OnCollisionEnter(rectButterfly);
	if (!viva)
	{
		//game->RestaPuntos();
		//instMuerte = SDL_GetTicks();
	}

	if (i >= 200 && i <= WIN_WIDTH && j >= 0 && j <= WIN_HEIGHT && viva) {
		//ArrowsGameObject::update();
		//mientras este viva y en los limites cada cierto tiempo le cambiamos la direccion?
	}

	if (SDL_GetTicks() < instMuerte + TIME_Animation && vuelo < 9) {
		vuelo++;
	}
	if (vuelo >= 9)
	{
		//se cae hacia abajo y es eliminada
		vel = Vector2D(vel.getX() * 0, 2);
		//aqui tiene que pasar cierto tiempo y despues ser eliminada
		game->KillObject(this);
	}
}