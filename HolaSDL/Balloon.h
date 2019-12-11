#ifndef BALLOON_H_
#define BALLOON_H_

#include "Texture.h"
#include "ArrowsGameObject.h"

//class Game;
const int POINTS = 5;

typedef unsigned int uint;
class Balloon : public ArrowsGameObject {

private:
	int color = 0;
	int estado = 0;
	bool explotado = false;
	uint instPinchazo = 0;
public:
	Balloon(Point2D esqIzq, uint w, uint h, Vector2D velocidad, Texture* globo, bool explotado, uint instPinchazo, GameState* game, int color);
	virtual void render();
	virtual void update();
	void loadFromFile(ifstream& input);
	void saveToFile(ofstream& outuput);
	//virtual ~Balloon() {};

};
#endif


