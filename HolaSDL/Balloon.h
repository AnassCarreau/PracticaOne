#ifndef Balloon_H_
#define Balloon_H_

#include "Vector2D.h"
#include <iostream>
#include "Texture.h"
class Game;
	using namespace std;
typedef unsigned int uint;
class Balloon
{
private:
	Point2D esqIzq = Point2D(600,600);
	uint h = 0;
	uint w = 0;
	Vector2D velocidad = Vector2D(0, 0);
	bool explotado = false;
	uint instPinchazo = 0;
	Texture* globo = nullptr;
	Game* tocando = nullptr;
public:
	Balloon();
	Balloon(Point2D esqIzq, uint ancho, uint alto, Vector2D vel, Texture* textura, bool explotado, uint instPinchazo, Game* tocando);
	void render();
	void update();
};
#endif

