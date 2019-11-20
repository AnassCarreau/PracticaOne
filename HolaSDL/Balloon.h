#ifndef Balloon_H_
#define Balloon_H_

#include "Texture.h"
#include "ArrowsGameObject.h"

//class Game;
typedef unsigned int uint;
class Balloon : public ArrowsGameObject {

private:
	Point2D esqIzq = Point2D(600, 600);
	uint h = 0;
	uint w = 0;
	Vector2D velocidad = Vector2D(0, 0);
	Texture* globo = nullptr;
	Game* game = nullptr;
	int color = 0;
	int estado = 0;
	bool explotado = false;
	uint instPinchazo = 0;
public:
	Balloon(Point2D esqIzq, uint w, uint h, Vector2D velocidad, Texture* globo, bool explotado, uint instPinchazo, Game* game, int color);
	virtual void render();
	virtual void update();
};
#endif


