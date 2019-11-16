#ifndef BUTTERFLY_H_
#define BUTTERFLY_H_
#include "ArrowsGameObject.h"
class Butterfly:public ArrowsGameObject
{
private:
	Point2D esqIzq;
	Vector2D vel;
	uint ancho, alto;
	Texture* textura;
	Game* game;
	public:	
		Butterfly(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* textura, Game* game);
		void update();
		void render();

};
#endif

