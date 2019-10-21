#include "Balloon.h"
#include "Game.h"
#include "Vector2D.h"
#include <random>

typedef unsigned int uint;


Balloon::Balloon() :esqIzq(), w(), h(), velocidad(), globo(), explotado(), instPinchazo(), tocando() {}

Balloon::Balloon(Point2D esqIzq, uint ancho, uint alto, Vector2D vel, Texture* textura, bool explotado, uint instPinchazo, Game* tocando, int color) 
	: esqIzq(esqIzq), w(ancho), h(alto), velocidad(vel), globo(textura), explotado(explotado), instPinchazo(instPinchazo), tocando(tocando), color(color){}

void Balloon::render() {
	SDL_Rect srcDest;
	srcDest.x = esqIzq.getX();
	srcDest.y = esqIzq.getY();
	srcDest.w = w;
	srcDest.h = h;
	globo->renderFrame(srcDest, color, 0, 0, SDL_FLIP_NONE);
}

bool Balloon::update() {
	double i = esqIzq.getX();
	double j = esqIzq.getY();
	
	//explotado =tocando->MiraChoques(esqIzq);
	if (i >= 0 && i <= WIN_WIDTH && j >= (-100) && j <= WIN_WIDTH && !explotado) {
		esqIzq = Point2D(i + velocidad.getX(), j - velocidad.getY());
		return false;
	}
	else
	{
		return true;
	}
}
	Point2D	Balloon::Posglobo() {
		return esqIzq.operator+(Vector2D(0, h / 2));
 }
	