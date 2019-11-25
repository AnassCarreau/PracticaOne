#include "Reward.h"
#include "Game.h"

Reward::Reward(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* premio, Texture* _burbuje,Game* game, int _color):ArrowsGameObject(esqIzq, vel, ancho, alto, premio, game){
	burbuja = true;
	burbuje = _burbuje;
	estado = 0;
	color = _color;

}

void Reward::update() {
	
	if (burbuja)
	{
		burbuja = !game->OnCollisionEnter(getDestRect(),i);

	}
	
	if (pos.getY() >= 0 && pos.getY() <= WIN_HEIGHT  ) {
		ArrowsGameObject::update();
	}
	else
	{
		
		game->KillObject(i);
	}
}

void Reward::render() {
	SDL_Rect* destRect = ArrowsGameObject::getCollisionRect();
	destRect->x = destRect->x - width/4 ;
	destRect->y = destRect->y - height/4 ;
	textura->renderFrame(*destRect, color, estado, 0, SDL_FLIP_NONE);
	if (burbuja)
	{
		destRect = ArrowsGameObject::getDestRect();
		
		burbuje->render(*destRect, SDL_FLIP_NONE);

	}
	estado++;
	if (estado==6)
	{
		estado = 0;
	}
}

void Reward::handleEvent(SDL_Event& event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN && !burbuja)
	{
		
		int errorX= abs( event.button.x-pos.getX());
		int errorY= abs(event.button.y-pos.getY());
		if (errorX<50 && errorY<50 )
		{
			
			game->KillObject(i);
		}	
	}
}

void Reward::saveToFile(ofstream& output) {
	ArrowsGameObject::saveToFile(output);
	if (burbuja) output << "burbuja" << endl;
	else output << "noburbuja" << endl;
	output << color << endl;
}

void Reward::loadFromFile(ifstream& input) {
	ArrowsGameObject::loadFromFile(input);
	string line;
	input >> line;
	if (line == "burbuja") burbuja = true;
	else burbuja = false;
	input >> color;
}



