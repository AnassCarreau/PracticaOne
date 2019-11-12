#ifndef REWARD_H_
#define REWARD_H_

#include "ArrowsGameObject.h";
#include "EventHandler.h";

class Reward:public ArrowsGameObject,public EventHandler
{
	public:
		bool premio;
		void update();
		void render();
		void handleEvent(SDL_Event& event);

};
#endif

