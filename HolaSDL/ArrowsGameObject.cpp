#include "ArrowsGameObject.h";

ArrowsGameObject::ArrowsGameObject(Point2D esqIzq, Vector2D vel, uint _width, uint _height, Texture* _textura, Game* _game)
{
	pos = esqIzq;
	width = _width;
	height = _height;
	velocity = vel;
	textura = _textura;
	game = _game;
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


