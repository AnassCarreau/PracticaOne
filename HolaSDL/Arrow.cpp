#include "Arrow.h"
#include "Vector2D.h"
#include"Game.h"


typedef unsigned int uint;


Arrow::Arrow():esqIzq(), ancho(), alto(), velocidad(),flecha(){}

Arrow::Arrow(Point2D esqIzq, uint ancho, uint alto, Vector2D vel, Texture* textura)
	: esqIzq(esqIzq), ancho(ancho), alto(alto), velocidad(vel), flecha(textura) {}
void Arrow::render() {
	SDL_Rect srcDest;
	srcDest.x = esqIzq.getX();
	srcDest.y = esqIzq.getY();
	srcDest.w = ancho;
	srcDest.h = alto;
	flecha->renderFrame(srcDest, 0, 0, 0, SDL_FLIP_NONE);
}

bool Arrow::update() {	
	esqIzq=esqIzq.operator+(velocidad);
	int i=	esqIzq.getX();
	return i > 800;
	
}
Point2D Arrow::PosFlecha() {
	return Point2D(esqIzq.getX(), esqIzq.getY());
}