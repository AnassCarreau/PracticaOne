#include "BigArrows.h"
#include "Game.h"

BigArrows::BigArrows(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* premio, Texture* _burbuje, Game* game, int _color) :Reward(esqIzq, vel, ancho, alto, premio,_burbuje, game,_color) 
{}
void BigArrows::accion(bool active) {
	if (!active)
	{
		suma *= -1;
		cout << "hola";
	}	
	game->ArrowSize(suma);

	
}

