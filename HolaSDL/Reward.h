#ifndef REWARD_H_
#define REWARD_H_

#include "ArrowsGameObject.h";
#include "EventHandler.h";

class Reward:public ArrowsGameObject,public EventHandler
{
private:
	Point2D esqIzq;
	Vector2D vel;
	uint ancho, alto;
	Texture* textura;
	Game* game;
	bool premio;
	public:
		Reward(Point2D esqIzq, Vector2D vel, uint ancho, uint alto, Texture* textura, Game* game, bool premio);
		virtual void update();
		virtual void render();
		virtual void handleEvent(SDL_Event& event);

};
#endif

