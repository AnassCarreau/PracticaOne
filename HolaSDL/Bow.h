#ifndef BOW_H_
#define BOW_H_

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Vector2D.h"
//#include "Arrow.h"
#include "Texture.h"
//#include "Game.h"
#include <iostream>

class Bow
{
private:
	Point2D esqIzq;
	double ancho, alto;
	Vector2D velocidad;
	//Arrow* flechaCarg;
	Texture* textura;
	//Game* juego;
	bool cargado;
public:
	Bow();
	Bow(Point2D esqIzq, double ancho, double alto, Vector2D vel, Texture* textura, bool cargado);
	void render();
	void update();
	void handleEvents();
};
#endif

