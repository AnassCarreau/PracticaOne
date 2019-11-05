#ifndef BOW_H_
#define BOW_H_
#include "Vector2D.h"
#include "Texture.h"
#include"Arrow.h"
//#include "EventHandler.h";
//#include "ArrowsGameObject.h";

class Game;

typedef unsigned int uint;

class Bow: public EventHandler,public ArrowsGameObject{
private:
	Point2D esqIzq = Point2D(0,0); 
	uint w = 0; // width
	uint h = 0; // height
	Vector2D velocidad = Vector2D(0,0);
	Texture* arco = nullptr;
	Texture* arcoC = nullptr;
	Game* juego=nullptr;
	Arrow* flecha = nullptr;
	bool cargado = false;
	int time = 0;
public:
	Bow();
	Bow(Point2D esqIzq, uint ancho, uint alto, Vector2D vel, Texture* textura,Texture* tectura, bool cargado,Game* game,Arrow*flechaCargada);
	void render();
	void update();
	void handleEvents(SDL_Event& event);
	
};
#endif

