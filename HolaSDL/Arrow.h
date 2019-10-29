#ifndef ARROW_H_
#define ARROW_H_

#include "Vector2D.h"
#include "Texture.h"
class Game;
class Arrow
{
private:
	Point2D esqIzq;
	uint ancho, alto;
	Vector2D velocidad;
	Texture* flecha;
	
public:
	Arrow();
	Arrow(Point2D esqIzq, uint ancho, uint alto, Vector2D vel, Texture* textura);
	void render();
	bool update();
	SDL_Rect* PosFlecha();
	//void IncrementaVel(double inc);
	//Vector2D DameVel();
};
#endif

