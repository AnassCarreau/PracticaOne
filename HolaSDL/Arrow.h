#ifndef ARROW_H_
#define ARROW_H_

#include "Texture.h"
#include "ArrowsGameObject.h";


class Game;
class Arrow: public ArrowsGameObject{

private:
	Point2D esqIzq;
	uint width, height;
	Vector2D velocity;
	Texture* flecha;
	
public:
	Arrow();
	Arrow(Point2D esqIzq, uint width, uint height, Vector2D vel, Texture* textura);
	void render();
	void update();
	SDL_Rect* PosFlecha();
	SDL_Rect* getCollisionRect();

	
};
#endif

