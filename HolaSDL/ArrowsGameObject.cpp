#include "ArrowsGameObject.h";
#include "Game.h";
#include "GameState.h";
#include "checkML.h"


ArrowsGameObject::ArrowsGameObject(Point2D esqIzq, Vector2D vel, uint _width, uint _height, Texture* _textura, GameState* _state) : SDLGameObject(esqIzq, _width, _height, _textura, _state) {
	velocity = vel;
}

 ArrowsGameObject::~ArrowsGameObject()
 {
	/* textura = nullptr;
	 game = nullptr;*/
 }

void ArrowsGameObject::render()
{
	SDLGameObject::render();
}
void ArrowsGameObject::update()
{
	pos = pos + velocity;
}

SDL_Rect ArrowsGameObject::getDestRect()
{
	return SDLGameObject::getDestRect();
}; 
SDL_Rect ArrowsGameObject::getCollisionRect()
{
	return SDLGameObject::getCollisionRect();
};
void ArrowsGameObject::saveToFile(ofstream& output)
{
	output << pos.getX() << endl;
	output << pos.getY() << endl;
	output << velocity.getX() << endl;
	output << velocity.getY() << endl;
	output << w << endl;
	output << h << endl;
}
void ArrowsGameObject::loadFromFile(ifstream &input)
{
	double x, y, velX, velY;
	input>> x;
	input >> y;
	pos = Point2D(x, y);
	input >> velX;
	input >> velY;
	velocity = Vector2D(velX, velY);
	input >> w;
	input >> h;	
}

void ArrowsGameObject::setItList(list<GameObject*>::iterator it)
{
	i = it;
}

