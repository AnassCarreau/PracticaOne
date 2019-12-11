#include "GiveMeArrows.h"
#include"Game.h"

GiveMeArrows::GiveMeArrows(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* premio, Texture* _burbuje, GameState* state, int _color) :Reward(esqIzq, vel, ancho, alto, premio, _burbuje, state, _color) {}

void GiveMeArrows::accion(bool active) {
	if (active)
	{
		dynamic_cast<PlayState*>(state)->AddArrows(1);

	}
}
