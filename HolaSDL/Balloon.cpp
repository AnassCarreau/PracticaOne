#include "Balloon.h"
#include "checkML.h"
#include "Game.h"


typedef unsigned int uint;
const int TIME_Animation = 600;

Balloon::Balloon(Point2D esqIzq, uint w, uint h, Vector2D velocidad, Texture* globo, bool _explotado, uint _instPinchazo, Game* game, int _color) : ArrowsGameObject(esqIzq, velocidad, w, h, globo, game){
	explotado = _explotado;
	instPinchazo = _instPinchazo;
	color = _color;
}

void Balloon::render() {
	SDL_Rect* destRect = ArrowsGameObject::getDestRect();
	//si el globo esta explotado renderizamos con animacion
	if (explotado) {
		textura->renderFrame(*destRect, color, estado , 0, SDL_FLIP_NONE);
	}
	//si no lo renderizamos normal
	else {
		textura->renderFrame(*destRect, color, 0, 0, SDL_FLIP_NONE);
	}
}

void  Balloon::update() {
	double i = pos.getX();
	double j = pos.getY();

	explotado = game->OnCollisionEnter(getCollisionRect(),this->i);
	if (explotado && instPinchazo == 0)
	{
		//game->AddPoints(POINTS,);
		instPinchazo = SDL_GetTicks();
	}

	if (j >= 0 && j <= WIN_HEIGHT) {
		ArrowsGameObject::update();
	}
	else
	{
		game->KillObject(this->i);
	}
	
	  
	if (SDL_GetTicks() < instPinchazo + TIME_Animation  && estado<7) {
		estado++;
	}
	if (estado>=7)
	{
		int estadistica = rand() % 3;
		if (estadistica == 0)
		{
			game->CreateReward(pos);
		}
		game->KillObject(this->i);
	}

}
 
	