#include "Bow.h"
#include "Game.h"
#include "checkML.h"
#include <iostream>
typedef unsigned int uint;
bool arriba=true;
bool abajo = true;

//Bow::Bow() :esqIzq(), w(), h(), velocidad(), arco(), arcoC(),cargado(),juego(),flecha(){}

Bow::Bow(Point2D esqIzq, uint ancho, uint alto, Vector2D vel, Texture* textura, Texture*texture2,bool cargado,Game*game,Arrow*flechaCargada) : esqIzq(esqIzq), w(ancho), h(alto), velocidad(vel), arco(textura),arcoC(texture2), cargado(cargado),juego(game),flecha(flechaCargada) {}

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
			 juego->CargaFlecha();

			 cargado = true;
		 }
		 else if (event.key.keysym.sym == SDLK_RIGHT && cargado)
		 {
			 juego->DisparaFlecha(esqIzq);
			 cargado = false;
		 }
	 }
 }
 void Bow::saveToFile(ofstream& output)const {


 }

	 
