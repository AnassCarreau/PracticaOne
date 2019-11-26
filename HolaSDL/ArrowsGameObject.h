#ifndef ARROWSGAMEOBJECT_H_
#define ARROWSGAMEOBJECT_H_

#include "GameObject.h";
#include "Vector2D.h";
#include "Texture.h";

#include <fstream>
#include <list>
class Game;
class ArrowsGameObject : public GameObject {

protected:
	Point2D pos;
	uint width, height;
	Vector2D velocity;
	Texture* textura;
	Game* game;

	list<GameObject*>::iterator i;
	ArrowsGameObject(Point2D pos, Vector2D vel, uint width, uint height, Texture* textura, Game* game);
	virtual ~ArrowsGameObject();
public:
	ArrowsGameObject();
	virtual void render();
	virtual void update();
	SDL_Rect* getDestRect();
	SDL_Rect* getCollisionRect();
	virtual void loadFromFile(ifstream& input);
	virtual void saveToFile(ofstream& outuput);
	void setItList(list<GameObject*>::iterator it);
	
};
#endif


