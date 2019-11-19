#include "Butterfly.h"

Butterfly::Butterfly(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* textura, Game* game):ArrowsGameObject(esqIzq, vel, ancho, alto, textura, game){}

void Butterfly::update() {

}

void Butterfly::render() {
	SDL_Rect destRect = ArrowsGameObject::getDestRect();
	textura->renderFrame(destRect, 0, 0, 0, SDL_FLIP_NONE);
}