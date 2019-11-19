#include "Reward.h"

Reward::Reward(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* textura, Game* game, bool _premio):ArrowsGameObject(esqIzq, vel, ancho, alto, textura, game){
	premio = _premio;
}

void Reward::update() {

}

void Reward::render() {
	SDL_Rect destRect = ArrowsGameObject::getDestRect();
	textura->render(destRect, SDL_FLIP_NONE);
}

void Reward::handleEvent(SDL_Event& event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN) {}


}