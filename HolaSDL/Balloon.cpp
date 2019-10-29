#include "Balloon.h"
#include "Game.h"
#include "Vector2D.h"

typedef unsigned int uint;
const int TIME_Animation = 600;

Balloon::Balloon() :esqIzq(), w(), h(), velocidad(), globo(), explotado(), instPinchazo(), game() {}

Balloon::Balloon(Point2D esqIzq, uint ancho, uint alto, Vector2D vel, Texture* textura, bool explotado, uint instPinchazo, Game* tocando, int color) 
	: esqIzq(esqIzq), w(ancho), h(alto), velocidad(vel), globo(textura), explotado(explotado), instPinchazo(instPinchazo), game(tocando), color(color){}

void Balloon::render() {
	SDL_Rect srcDest;
	srcDest.x = esqIzq.getX();
	srcDest.y = esqIzq.getY();
	srcDest.w = w;
	srcDest.h = h;

	if (explotado) {
		globo->renderFrame(srcDest, color, int(((SDL_GetTicks() / TIME_Animation) % 6)), 0, SDL_FLIP_NONE);
	}
	else {
		globo->renderFrame(srcDest, color, 0, 0, SDL_FLIP_NONE);
	}
}

bool Balloon::update() {
	double i = esqIzq.getX();
	double j = esqIzq.getY();
	SDL_Rect* rectBalloon = new SDL_Rect{ (int)esqIzq.getX(),(int)esqIzq.getY(),(int)w,(int)h };

	explotado = game->MiraChoques(rectBalloon);
	if ( instPinchazo==0 && explotado)
	{
		instPinchazo = SDL_GetTicks()+600;
	}
	if (j >= 0 && j <= WIN_HEIGHT && !explotado) {
		esqIzq = esqIzq.operator-(velocidad);
		return false;
	}
	else if (explotado)
	{
		if (instPinchazo  > SDL_GetTicks()) {

			return false;
		}
		else return true;
		
	}
}

 
	