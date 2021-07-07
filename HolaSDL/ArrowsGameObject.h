#ifndef ARROWSGAMEOBJECT_H_
#define ARROWSGAMEOBJECT_H_

#include "Vector2D.h";
#include "Texture.h";
#include <fstream>
#include <list>
#include "SDLGameObject.h"
//class GameState;


class ArrowsGameObject : public SDLGameObject {

protected:
	Vector2D velocity;
	
	list<GameObject*>::iterator i;
	ArrowsGameObject(Point2D pos, Vector2D vel, uint width, uint height, Texture* textura, GameState* state);
	virtual ~ArrowsGameObject();
public:
	virtual void render();
	virtual void update();
	virtual SDL_Rect getDestRect();
	virtual SDL_Rect getCollisionRect();
	virtual void loadFromFile(ifstream& input);
	virtual void saveToFile(ofstream& outuput);
	void setItList(list<GameObject*>::iterator it);
	
};
#endif


