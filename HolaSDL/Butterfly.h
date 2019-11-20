#ifndef BUTTERFLY_H_
#define BUTTERFLY_H_
#include "ArrowsGameObject.h"
class Butterfly:public ArrowsGameObject
{
private:
	Point2D esqIzq;
	Vector2D vel;
	uint ancho = 0, alto = 0;
	Texture* butterfly = nullptr;
	Game* game = nullptr;
	bool viva = true;
	int mariposon = 0;
	int vuelo = 0;
	int instMuerte = 0;
	public:	
		Butterfly(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* butterfly, Game* game);
		virtual void update();
		virtual void render();

};
#endif

