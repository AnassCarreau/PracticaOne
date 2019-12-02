#include "Reward.h"
#include "Game.h"

const int time_frame = 200;
Reward::Reward(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* premio, Texture* _burbuje,Game* game, int _color):ArrowsGameObject(esqIzq, vel, ancho, alto, premio, game){
	burbuja = true;
	burbuje = _burbuje;
	estado = 0;
	color = _color;
	time = SDL_GetTicks();

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
	SDL_Rect destRect = ArrowsGameObject::getCollisionRect();
	destRect.x = destRect.x - width/4 ;
	destRect.y = destRect.y - height/4 ;
	textura->renderFrame(destRect, color, estado, 0, SDL_FLIP_NONE);
	if (burbuja)
	{
		destRect = ArrowsGameObject::getDestRect();
		
		burbuje->render(destRect, SDL_FLIP_NONE);

	}
	if (time+time_frame<SDL_GetTicks())
	{
		estado++;
		time = SDL_GetTicks();
	}
	if (estado==6)
	{
		estado = 0;
	}
}

void Reward::handleEvent(SDL_Event& event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN && !burbuja && !power)
	{
		int errorX= abs( event.button.x-pos.getX());
		int errorY= abs(event.button.y-pos.getY());
		if (errorX<50 && errorY<50 )
		{
			power = true;
			accion(true);
			timeP = SDL_GetTicks();
			height = 10;
		}	
	}
	if (timeP + timePower < SDL_GetTicks() && power)
	{
		accion(false);
		game->KillObject(i);

	}
	
}

void Reward::saveToFile(ofstream& output) {
	output << "Premio"<<endl;
	output << color << endl;
	ArrowsGameObject::saveToFile(output);
	if (burbuja) output << "burbuja" << endl;
	else output << "noburbuja" << endl;
}

void Reward::loadFromFile(ifstream& input) {
	ArrowsGameObject::loadFromFile(input);
	string line;
	input >> line;
	if (line == "burbuja") burbuja = true;
	else burbuja = false;
}



