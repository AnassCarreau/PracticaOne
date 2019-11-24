#include "Reward.h"
#include "Game.h"

Reward::Reward(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* premio, Texture* _burbuje,Game* game, int _color):ArrowsGameObject(esqIzq, vel, ancho, alto, premio, game){
	burbuja = true;
	burbuje = _burbuje;
	estado = 0;
	color = _color;

}

void Reward::update() {
	
	if (burbuja)
	{
		burbuja = game->OnCollisionEnter(getDestRect(),i);

	}
	
	if (pos.getY() >= 0 && pos.getY() <= WIN_HEIGHT  ) {
		ArrowsGameObject::update();
	}
	else
	{
		game->KillObject(i);
	}
}

void Reward::render() {
	SDL_Rect* destRect = ArrowsGameObject::getDestRect();
	if (burbuja)
	{

		burbuje->render(*destRect, SDL_FLIP_NONE);

	}
	 destRect = ArrowsGameObject::getCollisionRect();
	 destRect->x = destRect->x - 20;
	 destRect->y = destRect->y - 20;

	textura->renderFrame(*destRect, color, estado, 0, SDL_FLIP_NONE);
	
	estado++;
	if (estado==6)
	{
		estado = 0;
	}
}

void Reward::handleEvent(SDL_Event& event)
{ 
	if (event.type == SDL_MOUSEBUTTONDOWN && !burbuja)
	{
		cout << "holajimmoncio";
		game->KillObject(i);

	}


}