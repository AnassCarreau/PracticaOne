#ifndef ARROW_H_
#define ARROW_H_

#include "Texture.h"
#include "ArrowsGameObject.h";

class Game;
class Arrow: public ArrowsGameObject{
private:
	int hits=0;
public:
	int getHits();
	Arrow(Vector2D dir, Texture* flecha, GameState* state, Point2D posIni, uint width, uint height);
	virtual void render();
	virtual void update();
	virtual ~Arrow() {};
	SDL_Rect getCollisionRect();
	void loadFromFile(ifstream& input);
	void saveToFile(ofstream& outuput);
};
#endif

