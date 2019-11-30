#ifndef BIGARROWS_H_
#define BIGARROWS_H_

#include "Reward.h";

class BigArrows:public Reward
{
public :
	//BigArrows();
	BigArrows(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* premio, Texture* _burbuje, Game* game, int _color);
		
		//Reward::Reward(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* premio, Texture* _burbuje, Game* game, int _color) :ArrowsGameObject(esqIzq, vel, ancho, alto, premio, game) {

	private:
		void accion();
};
#endif

