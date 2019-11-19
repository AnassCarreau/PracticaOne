#include "Balloon.h"
#include "Game.h"
#include "checkML.h"


typedef unsigned int uint;
const int TIME_Animation = 600;

Balloon::Balloon(Point2D esqIzq, uint ancho, uint alto, Vector2D vel, Texture* textura, bool _explotado, uint _instPinchazo, Game* tocando, int _color) : ArrowsGameObject(esqIzq, vel, ancho, alto, textura, tocando){
	explotado = _explotado;
	instPinchazo = _instPinchazo;
	color = _color;
}

void Balloon::render() {
	/*SDL_Rect destRect;
	destRect.x = esqIzq.getX();
	destRect.y = esqIzq.getY();
	destRect.w = w;
	destRect.h = h;*/
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
		esqIzq = esqIzq.operator-(velocidad);
		//return false;
	}
	  
	if (SDL_GetTicks() < instPinchazo + TIME_Animation  && estado<7) {
		estado++;
		//return false;
	}
	if (estado>=7)
	{
		game->KillObject(this);
	}
	//return true;
	/*if (true) game->killobject(this)*/

}
 
	