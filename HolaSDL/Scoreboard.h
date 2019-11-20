#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_

#include "Vector2D.h"
#include "Texture.h"
#include <vector>
#include "GameObject.h"
using namespace std;

class Game;
class Scoreboard:public GameObject
{
private:
	Point2D esqIzq = Point2D(0, 0);
	Texture* points=nullptr;
	Texture* arrows=nullptr;
	uint ancho = 0;
	uint alto = 0;
	static  const int MAX_ARROW_TEXTURES = 10;
	vector<int>digitos;
	int numberarrows;
	//int puntos = 0;

public:
	Scoreboard();
	Scoreboard(Point2D esqIzq,uint ancho , uint alto ,Texture* points, Texture* arrows,int numberArrows);
	void Puntuacion(int score);
	void Arrows();
	virtual void render();
	virtual void update();
	
};
#endif

