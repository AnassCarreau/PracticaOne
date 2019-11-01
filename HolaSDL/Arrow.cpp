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
SDL_Rect* Arrow::PosFlecha() {

	int pointX = esqIzq.getX() + 4*ancho / 5;
	int pointY = esqIzq.getY();
	int arrowwidth = ancho / 5;
	int arrowheight = alto;
	SDL_Rect* rectArrow = new SDL_Rect{ pointX, pointY, arrowwidth,arrowheight};
	
	return rectArrow;

}

