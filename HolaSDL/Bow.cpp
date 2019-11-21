#include "Bow.h"
#include "Game.h"
#include "checkML.h"
#include <iostream>
typedef unsigned int uint;
bool arriba=true;
bool abajo = true;


Bow::Bow(Point2D _esqIzq, uint _w, uint _h, Vector2D _velocidad, Texture* _arco, Texture* _arcoC,bool _cargado,Game*_game,Arrow* _flecha) : ArrowsGameObject(_esqIzq, _velocidad, _w, _h, _arco, _game) {
	arcoC = _arcoC;
	aux = arco;
	cargado = _cargado;
	flecha = _flecha;
}

 void Bow::render(){ 
	 //si el arco esta cargado renderizamos su imagen respectiva
	 if (cargado) {
		 arco = arcoC;
		 ArrowsGameObject::render();
	 }
	 //si no la normal
	 else
	 {
		 arco = aux;
		 ArrowsGameObject::render();
	 }
 }

 void Bow::update() {
	 if (esqIzq.getY()+velocidad.getY()+h>=600 && esqIzq.getY() + velocidad.getY() + h <=0)
	 {
		 ArrowsGameObject::update();
	 }
	
 }
 void Bow::handleEvents(SDL_Event& event) {
	 //EventHandler::handleEvent(event);
	 if (event.type == SDL_KEYDOWN) {

		 if (event.key.keysym.sym == SDLK_DOWN && velocidad.getY()<=0) {
			 velocidad = velocidad * (-1);
		 }
		 else  if (event.key.keysym.sym == SDLK_UP && velocidad.getY() >=0) {

			 velocidad = velocidad * (-1);
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

	 
