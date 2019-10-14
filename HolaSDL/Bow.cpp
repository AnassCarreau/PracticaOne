#include "Bow.h"
#include "Vector2D.h"
#include "Game.h"
//#include "Texture.h"

typedef unsigned int uint;

Bow::Bow() :esqIzq(), w(), h(), velocidad(), arco(), cargado(){}

Bow::Bow(Point2D esqIzq, uint ancho, uint alto, Vector2D vel, Texture* textura, bool cargado) : esqIzq(esqIzq), w(ancho), h(alto), velocidad(vel), arco(textura), cargado(cargado) {}

 void Bow::render(){
	 SDL_Rect srcDest;
	 
	 srcDest.x = 0;
	 srcDest.y = esqIzq.getY();
	 srcDest.w = w;
	 srcDest.h = h;
	 arco->render(srcDest, SDL_FLIP_NONE);
 }

 void Bow::update() {
	 uint i = esqIzq.getY();
	 esqIzq = Point2D(0, i  % 600);
 }
 void Bow::handleEvents(SDL_Event& event) {
	 if (event.type == SDL_KEYDOWN) {

		 if (event.key.keysym.sym == SDLK_DOWN) {

			esqIzq= esqIzq.operator+(velocidad);
		 }
		 else  if (event.key.keysym.sym == SDLK_UP) {

			esqIzq= esqIzq.operator-(velocidad);
		 }
	 }
 }
