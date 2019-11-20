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
	Arrow(Vector2D dir, Texture* tex, Game* game, Point2D posIni, int ancho, int alto);
	virtual void render();
	virtual void update();
	SDL_Rect* PosFlecha();
	SDL_Rect* getCollisionRect();
};
#endif

