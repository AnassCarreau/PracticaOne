#ifndef ARROWSGAMEOBJECT_H_
#define ARROWSGAMEOBJECT_H_

#include "GameObject.h";
#include "Game.h";
#include "Vector2D.h";

class ArrowsGameObject : public GameObject{

	private:

		Point2D pos;
		uint width, height;
		Vector2D velocity;
		Texture* textura;
		Game* game;
		vector<int>::iterator i;
protected:
	ArrowsGameObject();

	public:
		void render();
		void update();
		SDL_Rect getDestRect();
		SDL_Rect* getCollisionRect();
		void loadFromFile(ifstream &input);
		void saveToFile(ofstream &outuput);
		void setItList();
		ArrowsGameObject(Point2D pos, uint width, uint height, Vector2D vel, Texture* textura,Game* game);

};
#endif


