#ifndef GIVEMEARROWS_H_
#define GIVEMEARROWS_H_

#include "Reward.h";

class GiveMeArrows:public Reward
{
	public:

	GiveMeArrows(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* premio, Texture* _burbuje, GameState* state, int _color);
	private:
		void accion(bool active);
};
#endif

