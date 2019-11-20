#include "Butterfly.h"

Butterfly::Butterfly(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* butterfly, Game* game):ArrowsGameObject(esqIzq, vel, ancho, alto, butterfly, game){}

void Butterfly::update() {

}

void Butterfly::render() {
	SDL_Rect destRect = ArrowsGameObject::getDestRect();
	butterfly->renderFrame(destRect, 0, 0, 0, SDL_FLIP_NONE);
}