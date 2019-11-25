#ifndef BOW_H_
#define BOW_H_
#include "Vector2D.h";
#include "Texture.h";
#include "EventHandler.h";
#include "ArrowsGameObject.h";


class Game;

typedef unsigned int uint;

class Bow: public ArrowsGameObject,public EventHandler{
private:
	
	Texture* arcoC = nullptr;
	Texture* aux = nullptr;
	bool cargado = false;
	int time = 0;
	Vector2D velaux = Vector2D(0, 0);
	bool mov = false;
public:
	Bow(Point2D esqIzq, uint w, uint h, Vector2D velocidad, Texture* arco, Texture* arcoC,  Game* game);
	virtual void render();
	virtual void update();
	//virtual ~Bow() {};

	virtual void handleEvent(SDL_Event& event);
	// ~Bow() {};


protected:
	void saveToFile(ofstream &output);

};
#endif

