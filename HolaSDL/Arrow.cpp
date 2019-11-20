#include "Arrow.h"
#include "checkML.h"


typedef unsigned int uint;

Arrow::Arrow(Vector2D dir, Texture* flecha, Game* game, Point2D posIni, uint width, uint height) : ArrowsGameObject(posIni, dir, width, height, flecha, game) {}

void Arrow::render() {
	/*SDL_Rect destRect;
	destRect.x = esqIzq.getX();
	destRect.y = esqIzq.getY();
	destRect.w = width;
	destRect.h = height;*/
	SDL_Rect destRect = ArrowsGameObject::getDestRect();
	flecha->render(destRect, SDL_FLIP_NONE);
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


