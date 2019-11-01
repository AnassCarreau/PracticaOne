#ifndef ARROW_H_
#define ARROW_H_

#include "Vector2D.h"
#include "Texture.h"
class Game;
class Arrow
{
private:
	Point2D esqIzq;
	uint width, height;
	Vector2D velocity;
	Texture* flecha;
	
public:
	Arrow();
	Arrow(Point2D esqIzq, uint width, uint height, Vector2D vel, Texture* textura);
	void render();
	bool update();
	SDL_Rect* PosFlecha();
	
};
#endif

