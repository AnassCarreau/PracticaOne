#include "Arrow.h"
#include "checkML.h"


typedef unsigned int uint;


//Arrow::Arrow():esqIzq(), width(), height(), velocity(),flecha(){}

Arrow::Arrow(Point2D esqIzq, uint width, uint height, Vector2D vel, Texture* textura)
	: esqIzq(esqIzq), width(width), height(height), velocity(vel), flecha(textura) {}
void Arrow::render() {
	SDL_Rect destRect;
	destRect.x = esqIzq.getX();
	destRect.y = esqIzq.getY();
	destRect.w = width;
	destRect.h = height;
	flecha->renderFrame(destRect, 0, 0, 0, SDL_FLIP_NONE);
}

void Arrow::update() {	
	esqIzq=esqIzq.operator+(velocity);
	int i=	esqIzq.getX();
	//return i > 800;
	
}
//metodo para saber el rect de la flecha
SDL_Rect* Arrow::getCollisionRect() {

	SDL_Rect* rectArrow = ArrowsGameObject::getCollisionRect();
	rectArrow->x += 3 * width / 4;
	rectArrow->w = width / 4;
	
	
	return rectArrow;

}
SDL_Rect* Arrow::PosFlecha() {

	int pointX = esqIzq.getX() + 3 * width / 4;
	int pointY = esqIzq.getY();
	int arrowwidth = width / 4;
	int arrowheight = height;
	SDL_Rect* rectArrow = new SDL_Rect{ pointX, pointY, arrowwidth,arrowheight };

	return rectArrow;

}

