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
	int time = 0;
	bool power = false;
	int timeP = 0;
	int timePower = 6000;
	public:
		Reward(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* premio,Texture*burbuje, GameState* state,int color );
		virtual void update();
		virtual void render();
	//	virtual ~Reward() {};
		virtual void handleEvent(SDL_Event& event);
		void saveToFile(ofstream& output);
		void loadFromFile(ifstream& input);
		virtual void accion(bool active)=0;

};
#endif

