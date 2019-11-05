#pragma once
#ifndef REWARD_H_
#define REWARD_H_
#include "ArrowsGameObject.h"
class Reward:public ArrowsGameObject,public EventHandler
{
private :
	bool premio;
	void update();
	void render();
	void handleEvent();

};
#endif

