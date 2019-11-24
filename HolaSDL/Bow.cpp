#include "Bow.h"
#include "Game.h"
#include "checkML.h"
#include <iostream>
typedef unsigned int uint;

/*Bow::~Bow() 
{

};*/
Bow::Bow(Point2D _pos, uint _w, uint _h, Vector2D _velocity, Texture* _texture, Texture* _textureC,Game*_game) : ArrowsGameObject(_pos, _velocity, _w, _h, _texture, _game) {
	arcoC = _textureC;
	aux = textura;
	cargado = false;
	mov = false;
	
}




 void Bow::render(){ 
	 //si el texture esta cargado renderizamos su imagen respectiva
	 if (cargado) {
		 textura = arcoC;
		 ArrowsGameObject::render();
	 }
	 //si no la normal
	 else
	 {
		 textura = aux;
		 ArrowsGameObject::render();
	 }
 }

 void Bow::update() {
	 if (pos.getY()+velocity.getY()+height <=600 && pos.getY() + velocity.getY()  >=0 && mov)
	 {
		 ArrowsGameObject::update();
		 mov = false;
	 }

 }
 void Bow::handleEvent(SDL_Event& event) {
	 if (event.type == SDL_KEYDOWN) {
		 switch (event.key.keysym.sym){
		 case SDLK_DOWN: mov = true;
			 if (velocity.getY() <= 0) { velocity = velocity * (-1); }
			 break;
		 case SDLK_UP: mov = true;
			 if (velocity.getY() >= 0) { velocity = velocity * (-1); }
			 break;
		 case SDLK_LEFT:
			 if (!cargado){
				 game->CargaFlecha();
				 cargado = true;
			 }
			 break;
		 case SDLK_RIGHT:
			 if (cargado) {
				 game->DisparaFlecha(pos);
				 cargado = false;
			 }
			 break;
		 }
	 }
 }
 void Bow::saveToFile(ofstream& output){
	 if (cargado) output << "1";
	 else output << "0";
	 output << time;
	 ArrowsGameObject::saveToFile (output);
 }

	 
