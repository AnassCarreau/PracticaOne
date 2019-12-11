#ifndef BIGARROWS_H_
#define BIGARROWS_H_

#include "Reward.h";

class BigArrows:public Reward
{
public :
	int suma = 20;
	BigArrows(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* premio, Texture* _burbuje, GameState* state, int _color);
private:
	void accion(bool active);
};
#endif

