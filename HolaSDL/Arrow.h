#ifndef ARROW_H_
#define ARROW_H_

#include "Texture.h"
#include "ArrowsGameObject.h";


class Game;
class Arrow: public ArrowsGameObject{

private:
	Point2D esqIzq;
	uint width = 0, height = 0;
	Vector2D velocity;
	Texture* flecha = nullptr;
	
public:
	Arrow(Vector2D dir, Texture* flecha, Game* game, Point2D posIni, uint width, uint height);
	virtual void render();
	virtual void update();
	SDL_Rect* PosFlecha();
	SDL_Rect* getCollisionRect();
};
#endif

