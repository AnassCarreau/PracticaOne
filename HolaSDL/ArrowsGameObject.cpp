#include "ArrowsGameObject.h"

ArrowsGameObject::ArrowsGameObject(Point2D esqIzq, uint width, uint height, Vector2D vel, Texture* textura, Game* game)
	: pos(esqIzq), width(width), height(height), velocity(vel), textura(textura), game(game)
{
	setItList();
}
void ArrowsGameObject::render()
{
	
	textura->renderFrame(getDestRect(), 0, 0, 0, SDL_FLIP_NONE);

}
void ArrowsGameObject::update()
{

}
SDL_Rect ArrowsGameObject::getDestRect()
{
	SDL_Rect destRect;
	destRect.x = 0;
	destRect.y = pos.getY();
	destRect.w = width;
	destRect.h = height;
	return destRect;

}; 
SDL_Rect* ArrowsGameObject::getCollisionRect()
{
	int pointX = pos.getX();
	int pointY = pos.getY();
	int arrowwidth = width;
	int arrowheight = height;
	SDL_Rect* rectArrow = new SDL_Rect{ pointX, pointY, arrowwidth,arrowheight };
	return rectArrow;
};
void ArrowsGameObject::saveToFile(ofstream &output)
{

}
void ArrowsGameObject::loadFromFile(ifstream &input)
{

}


