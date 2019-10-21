#include "Bow.h"
#include "Vector2D.h"
#include "Game.h"
#include"Arrow.h"
#include "Texture.h"

typedef unsigned int uint;
bool arriba=true;
bool abajo = true;

Bow::Bow() :esqIzq(), w(), h(), velocidad(), arco(), cargado(),juego(),flecha(){}

Bow::Bow(Point2D esqIzq, uint ancho, uint alto, Vector2D vel, Texture* textura, bool cargado,Game*game,Arrow*flechaCargada) : esqIzq(esqIzq), w(ancho), h(alto), velocidad(vel), arco(textura), cargado(cargado),juego(game),flecha(flechaCargada) {}

 void Bow::render(){
	 SDL_Rect srcDest;
	 srcDest.x = 0;
	 srcDest.y = esqIzq.getY();
	 srcDest.w = w;
	 srcDest.h = h;
	 arco->render(srcDest, SDL_FLIP_NONE);
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
			 juego->CargaFlecha(esqIzq,flecha);
			 
			 
		 }
		 else if (event.key.keysym.sym == SDLK_RIGHT && cargado)
		 {
			 juego->DisparaFlecha(esqIzq);
		 }
	 }


 }
 
