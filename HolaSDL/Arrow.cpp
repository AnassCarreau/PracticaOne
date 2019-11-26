#include "Arrow.h"
#include "Game.h"
#include "checkML.h"


typedef unsigned int uint;
Arrow::Arrow():ArrowsGameObject() {}

Arrow::Arrow(Vector2D dir, Texture* flecha, Game* game, Point2D posIni, uint width, uint height) : ArrowsGameObject(posIni, dir, width, height, flecha, game)
{
	hits = 0;
}

void Arrow::render() {
	ArrowsGameObject::render();
}

void Arrow::update() {	
	if ( pos.getX()+width  < WIN_WIDTH)
	{
		ArrowsGameObject::update();
	}
	else
	{
		game->KillObject(i);
	}
}
//metodo para saber el rect de la flecha
SDL_Rect* Arrow::getCollisionRect() {
	SDL_Rect* rectArrow = ArrowsGameObject::getCollisionRect();
	rectArrow->x += 3 * width / 4;
	rectArrow->w = width / 4;
	return rectArrow;
}
int Arrow::getHits()
{
	hits++;
	return hits;
}

void Arrow::saveToFile(ofstream& output) {
	ArrowsGameObject::saveToFile(output);
}

void Arrow::loadFromFile(ifstream& input) {
	ArrowsGameObject::loadFromFile(input);
}




