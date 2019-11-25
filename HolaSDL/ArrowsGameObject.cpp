#include "ArrowsGameObject.h";
#include "Game.h";

ArrowsGameObject::ArrowsGameObject(Point2D esqIzq, Vector2D vel, uint _width, uint _height, Texture* _textura, Game* _game):pos(esqIzq),velocity ( vel) ,width ( _width),height ( _height),textura ( _textura),game( _game)
{}


void ArrowsGameObject::render()
{
	textura->render(*getDestRect(), SDL_FLIP_NONE);
}
void ArrowsGameObject::update()
{
	pos = pos + velocity;
}

SDL_Rect* ArrowsGameObject::getDestRect()
{
	return new SDL_Rect{ (int)pos.getX(),  (int)pos.getY(),(int)width,(int)height };
}; 
SDL_Rect* ArrowsGameObject::getCollisionRect()
{
	
	int pointX = pos.getX()+width/2;
	int pointY = pos.getY()+height/2;
	int arrowwidth = width/2;
	int arrowheight = height/2;
	SDL_Rect* rectArrow = new SDL_Rect{ pointX, pointY, arrowwidth,arrowheight };
	return rectArrow;
};
void ArrowsGameObject::saveToFile(ofstream& output)
{
	//abrimos el archivo
	output.open("guardados.txt");
	//si no se abre lanzamos excepcion
	if (!output.is_open()) cout << "No se ha podido guardar, no se encuentra el archivo" << endl;
	//si se puede abrir guardamos la partida
	else {

	}
}
void ArrowsGameObject::loadFromFile(ifstream &input)
{
	//abrimos el archivo
	input.open("guardados.txt");
	//si no se puede abrir lanzamos una excepcion
	if (!input.is_open()) cout << "No se encuentra el fichero" << endl;
	//si se abre cargamos el archivo
	else {

	}
}

void ArrowsGameObject::setItList(list<GameObject*>::iterator it)
{
	i = it;
}

