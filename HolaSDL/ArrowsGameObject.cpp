#include "ArrowsGameObject.h";
#include "Game.h";

ArrowsGameObject::ArrowsGameObject(Point2D esqIzq, Vector2D vel, uint _width, uint _height, Texture* _textura, Game* _game):pos(esqIzq),velocity ( vel) ,width ( _width),height ( _height),textura ( _textura),game( _game)
{}

 ArrowsGameObject::~ArrowsGameObject()
 {
	 textura = nullptr;
	 game = nullptr;
 }

void ArrowsGameObject::render()
{
	textura->render(getDestRect(), SDL_FLIP_NONE);
}
void ArrowsGameObject::update()
{
	pos = pos + velocity;
}

SDL_Rect ArrowsGameObject::getDestRect()
{
	return SDL_Rect{ (int)pos.getX(),  (int)pos.getY(),(int)width,(int)height };
}; 
SDL_Rect ArrowsGameObject::getCollisionRect()
{
	int pointX = pos.getX()+width/2;
	int pointY = pos.getY()+height/2;
	int arrowwidth = width/2;
	int arrowheight = height/2;
	return SDL_Rect{ pointX, pointY, arrowwidth,arrowheight };
};
void ArrowsGameObject::saveToFile(ofstream& output)
{
	output << pos.getX() << endl;
	output << pos.getY() << endl;
	output << velocity.getX() << endl;
	output << velocity.getY() << endl;
	output << width << endl;
	output << height << endl;
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
	input >> width;
	input >> height;	
}

void ArrowsGameObject::setItList(list<GameObject*>::iterator it)
{
	i = it;
}

