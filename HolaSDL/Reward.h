#ifndef REWARD_H_
#define REWARD_H_

#include "ArrowsGameObject.h";
#include "EventHandler.h";

class Reward:public ArrowsGameObject,public EventHandler
{
private:
	bool burbuja = false;
	Texture* burbuje = nullptr;
	int color = 0;
	int estado = 0;
	public:
		Reward();
		Reward(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* premio,Texture*burbuje, Game* game,int color );
		virtual void update();
		virtual void render();
	//	virtual ~Reward() {};
		virtual void handleEvent(SDL_Event& event);
		void saveToFile(ofstream& output);
		void loadFromFile(ifstream& input);
};
#endif

