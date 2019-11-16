#ifndef ARROWSGAMEOBJECT_H_
#define ARROWSGAMEOBJECT_H_

#include "GameObject.h";
#include "Game.h";
#include "Vector2D.h";
#include "Texture.h";
#include <fstream>
#include <vector>;

class ArrowsGameObject : public GameObject{

	private:
		Point2D pos;
		uint width, height;
		Vector2D velocity;
		Texture* textura;
		Game* game;
		//vector<int>::iterator i;
	public:
		void render();
		void update();
		SDL_Rect getDestRect();
		SDL_Rect* getCollisionRect();
		void loadFromFile(ifstream &input);
		void saveToFile(ofstream &outuput);
		void setItList();
		ArrowsGameObject(Point2D pos, Vector2D vel, uint width, uint height, Texture* textura,Game* game);
};
#endif


