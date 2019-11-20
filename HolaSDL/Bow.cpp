#include "Bow.h"
#include "Game.h"
#include "checkML.h"
#include <iostream>
typedef unsigned int uint;
bool arriba=true;
bool abajo = true;


Bow::Bow(Point2D esqIzq, uint w, uint h, Vector2D velocidad, Texture* arco, Texture* _arcoC,bool _cargado,Game*game,Arrow* _flecha) : ArrowsGameObject(esqIzq, velocidad, w, h, arco, game) {
	arcoC = _arcoC;
	cargado = _cargado;
	flecha = _flecha;
}

 void Bow::render(){
	 
	 SDL_Rect destRect=ArrowsGameObject::getDestRect();
	 //si el arco esta cargado renderizamos su imagen respectiva
	 if(cargado)
		 arcoC->render(destRect, SDL_FLIP_NONE);
	 //si no la normal
	 else
	 {
		 arco->render(destRect, SDL_FLIP_NONE);
	 }
 }

 void Bow::update() {
	 
	 if (esqIzq.getY()+h>=600)
	 {
		 abajo = false;

	 }
	 else if (esqIzq.getY()<=0)
	 {
		 arriba = false;
	 }
	 else
	 {
		 abajo =arriba= true;
	 }
	
 }
 void Bow::handleEvents(SDL_Event& event) {
	 if (event.type == SDL_KEYDOWN) {

		 if (event.key.keysym.sym == SDLK_DOWN && abajo) {

			 esqIzq = esqIzq.operator+(velocidad);
		 }
		 else  if (event.key.keysym.sym == SDLK_UP && arriba) {

			 esqIzq = esqIzq.operator-(velocidad);

		 }
		 else if (event.key.keysym.sym == SDLK_LEFT && !cargado)
		 {
			 game->CargaFlecha();

			 cargado = true;
		 }
		 else if (event.key.keysym.sym == SDLK_RIGHT && cargado)
		 {
			 game->DisparaFlecha(esqIzq);
			 cargado = false;
		 }
	 }
 }
 void Bow::saveToFile(ofstream& output){
	 if (cargado) output << "1";
	 else output << "0";
	 output << time;
	 ArrowsGameObject::saveToFile (output);
 }

	 
