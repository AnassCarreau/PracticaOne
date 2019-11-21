#ifndef BOW_H_
#define BOW_H_
#include "Vector2D.h";
#include "Texture.h";
#include"Arrow.h";
#include "EventHandler.h";
#include "ArrowsGameObject.h";


class Game;

typedef unsigned int uint;

class Bow: public ArrowsGameObject{
private:
	Point2D esqIzq; 
	uint w; // width
	uint h; // height
	Vector2D velocidad;
	Texture* arco;
	Texture* arcoC = nullptr;
	Texture* aux = nullptr;
	Game* game;
	Arrow* flecha = nullptr;
	bool cargado = false;
	int time = 0;
public:
	Bow(Point2D esqIzq, uint w, uint h, Vector2D velocidad, Texture* arco, Texture* arcoC, bool cargado, Game* game, Arrow* flecha);
	virtual	void render();
	virtual	void update();
protected:
	virtual void handleEvents(SDL_Event& event);
	void saveToFile(ofstream &output);
};
#endif

