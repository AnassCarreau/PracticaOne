#include "GiveMeArrows.h"
#include"Game.h"

GiveMeArrows::GiveMeArrows(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* premio, Texture* _burbuje, Game* game, int _color) :Reward(esqIzq, vel, ancho, alto, premio, _burbuje, game, _color) {}

void GiveMeArrows::accion(bool active) {
	if (active)
	{
		game->AddArrows(1);

	}
}
