#include "Bow.h"
#include "Vector2D.h"
#include <math.h>
#include <iostream>

typedef unsigned int uint;

Bow::Bow() :esqIzq(), w(), h(), velocidad(), arco(), cargado(){}

Bow::Bow(Point2D esqIzq, uint ancho, uint alto, Vector2D vel, Texture* textura, bool cargado) : esqIzq(esqIzq), w(ancho), h(alto), velocidad(vel), arco(textura), cargado(cargado) {}

 void Bow::render(){
	 SDL_Rect srcDest;
	 srcDest.x = esqIzq.getX();
	 srcDest.y = esqIzq.getY();
	 arco->render(srcDest, SDL_FLIP_NONE);
 }

 void Bow::update() {

 }

 void Bow::handleEvents(SDL_Event& event) {

 }
