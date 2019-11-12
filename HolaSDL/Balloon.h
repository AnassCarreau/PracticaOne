#ifndef Balloon_H_
#define Balloon_H_


#include "Vector2D.h"
#include "Texture.h"
class Game;
typedef unsigned int uint;
class Balloon : public ArrowsGameObject {

private:
	Point2D esqIzq = Point2D(600, 600);
	uint h = 0;
	uint w = 0;
	Vector2D velocidad = Vector2D(0, 0);
	bool explotado = false;
	uint instPinchazo = 0;
	Texture* globo = nullptr;
	Game* game = nullptr;
	int color = 0;
	int estado = 0;
public:
	//Balloon();
//	Balloon(Point2D esqIzq, uint ancho, uint alto, Vector2D vel, Texture* textura, bool explotado, uint instPinchazo, Game* tocando, int color);
	Balloon() :ArrowsGameObject(esqIzq, w, h, velocidad, globo, game) {};

	void render();
	//bool update();
	void update();
};
#endif


