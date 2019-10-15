#include "Balloon.h"
#include "Game.h"
#include "Vector2D.h"
#include <random>

typedef unsigned int uint;


Balloon::Balloon() :esqIzq(), w(), h(), velocidad(), globo(), explotado(), instPinchazo(), tocando() {}

Balloon::Balloon(Point2D esqIzq, uint ancho, uint alto, Vector2D vel, Texture* textura, bool explotado, uint instPinchazo, Game* tocando) 
	: esqIzq(esqIzq), w(ancho), h(alto), velocidad(vel), globo(textura), explotado(explotado), instPinchazo(instPinchazo), tocando(tocando){}

void Balloon::render() {
	SDL_Rect srcDest;
	srcDest.x = esqIzq.getX();
	//srcDest.x = 600;
	srcDest.y = esqIzq.getY();
	//srcDest.y = 520;
	srcDest.w = w;
	srcDest.h = h;
	globo->renderFrame(srcDest, 0, 0, 0, SDL_FLIP_NONE);
}

void Balloon::update() {
	double i = esqIzq.getX();
	double j = esqIzq.getY();
	if (i >= 0 && i <= 600 && j >= (-100) && j <= 600) {
		esqIzq = Point2D(i + velocidad.getX(), j - velocidad.getY());
	}
	
	

}