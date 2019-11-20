#include "Balloon.h"
#include "Game.h"
#include "checkML.h"


typedef unsigned int uint;
const int TIME_Animation = 600;

Balloon::Balloon(Point2D esqIzq, uint w, uint h, Vector2D velocidad, Texture* globo, bool _explotado, uint _instPinchazo, Game* game, int _color) : ArrowsGameObject(esqIzq, velocidad, w, h, globo, game){
	explotado = _explotado;
	instPinchazo = _instPinchazo;
	color = _color;
}

void Balloon::render() {
	SDL_Rect destRect = ArrowsGameObject::getDestRect();
	//si el globo esta explotado renderizamos con animacion
	if (explotado) {
		globo->renderFrame(destRect, color, estado , 0, SDL_FLIP_NONE);
	}
	//si no lo renderizamos normal
	else {
		globo->renderFrame(destRect, color, 0, 0, SDL_FLIP_NONE);
	}
}

void  Balloon::update() {
	double i = esqIzq.getX();
	double j = esqIzq.getY();
	SDL_Rect* rectBalloon = new SDL_Rect{ (int)esqIzq.getX(),(int)esqIzq.getY(),(int)w,(int)h };

	explotado = game->OnCollisionEnter(rectBalloon);
	if (explotado && instPinchazo == 0)
	{
		game->AddPoints();
		instPinchazo = SDL_GetTicks();
	}

	if (j >= 0 && j <= WIN_HEIGHT && !explotado) {
		ArrowsGameObject::update();
	}
	  
	if (SDL_GetTicks() < instPinchazo + TIME_Animation  && estado<7) {
		estado++;
	}
	if (estado>=7)
	{
		game->KillObject(this);
	}
	/*if (true) game->killobject(this)*/

}
 
	