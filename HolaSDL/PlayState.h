#ifndef PLAYSTATE_H_
#define PLAYSTATE_H_

#include "GameState.h"

class PlayState:public GameState
{
private:
	//variables de game que usaremos para el estado play
public:
	PlayState(list<GameObject*> escenario, list<EventHandler*> eventos, Game* game);
	virtual void update();
	virtual void render();
	virtual void handleEvent();
};
#endif

