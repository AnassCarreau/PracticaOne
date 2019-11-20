#include "Reward.h"

Reward::Reward(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* premio, Game* game, bool _burbuja):ArrowsGameObject(esqIzq, vel, ancho, alto, premio, game){
	burbuja = _burbuja;
}

void Reward::update() {

}

void Reward::render() {
	SDL_Rect destRect = ArrowsGameObject::getDestRect();
	premio->render(destRect, SDL_FLIP_NONE);
}

void Reward::handleEvent(SDL_Event& event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN) {}


}