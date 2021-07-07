#include "Arrow.h"
#include "Game.h"
#include "checkML.h"


typedef unsigned int uint;

Arrow::Arrow(Vector2D dir, Texture* flecha, GameState* state, Point2D posIni, uint width, uint height) : ArrowsGameObject(posIni, dir, width, height, flecha, state)
{
	hits = 0;
}

void Arrow::render() {
	ArrowsGameObject::render();
}

void Arrow::update() {	
	if ( pos.getX()+w  < WIN_WIDTH)
	{
		ArrowsGameObject::update();
	}
	else
	{
		dynamic_cast<PlayState*>(state)->KillObject(i);
	}
}
//metodo para saber el rect de la flecha
SDL_Rect Arrow::getCollisionRect() {
	SDL_Rect rectArrow = ArrowsGameObject::getCollisionRect();
	rectArrow.x += 3 * w / 4;
	rectArrow.w = w / 4;
	return rectArrow;
}
int Arrow::getHits()
{
	hits++;
	return hits;
}

void Arrow::saveToFile(ofstream& output) {
	output << "Flecha" <<endl;
	ArrowsGameObject::saveToFile(output);
}

void Arrow::loadFromFile(ifstream& input) {
	ArrowsGameObject::loadFromFile(input);
}




