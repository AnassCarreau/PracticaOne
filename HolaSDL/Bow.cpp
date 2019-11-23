#include "Bow.h"
#include "Game.h"
#include "checkML.h"
#include <iostream>
typedef unsigned int uint;


Bow::Bow(Point2D _pos, uint _w, uint _h, Vector2D _velocity, Texture* _texture, Texture* _textureC,Game*_game) : ArrowsGameObject(_pos, _velocity, _w, _h, _texture, _game) {
	arcoC = _textureC;
	aux = textura;
	cargado = false;
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
	 if (pos.getY()+velocity.getY()+height <=600 && pos.getY() + velocity.getY()  >=0 )
	 {
		 ArrowsGameObject::update();
	 }

 }
 void Bow::handleEvent(SDL_Event& event) {
	 if (event.type == SDL_KEYDOWN) {

		 if (event.key.keysym.sym == SDLK_DOWN && velocity.getY()<=0) {
			 velocity = velocity * (-1);
		 }
		 else  if (event.key.keysym.sym == SDLK_UP && velocity.getY() >=0) {

			 velocity = velocity * (-1);

		 }
		 else if (event.key.keysym.sym == SDLK_LEFT && !cargado)
		 {
			 game->CargaFlecha();

			 cargado = true;
		 }
		 else if (event.key.keysym.sym == SDLK_RIGHT && cargado)
		 {
			 game->DisparaFlecha(pos);
			 cargado = false;
		 }
		 cout << velocity.getY();
	 }
 }
 void Bow::saveToFile(ofstream& output){
	 if (cargado) output << "1";
	 else output << "0";
	 output << time;
	 ArrowsGameObject::saveToFile (output);
 }

	 
