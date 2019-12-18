#include "BigArrows.h"
#include "Game.h"
#include "checkML.h"

BigArrows::BigArrows(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* premio, Texture* _burbuje, GameState* state, int _color) :Reward(esqIzq, vel, ancho, alto, premio,_burbuje, state,_color) {}
void BigArrows::accion(bool active) {
	if (!active)
	{
		suma *= -1;
	}	
	dynamic_cast<PlayState*>(state)->ArrowSize(suma);
}

