#ifndef PLAYSTATE_H_
#define PLAYSTATE_H_

#include "GameState.h"

class PlayState:public GameState
{
private:
	//variables de game que usaremos para el estado play
	static const std::string s_playID;
public:
	PlayState(list<GameObject*> escenario, list<EventHandler*> eventos, Game* game);
	virtual void update();
	virtual void render();
	virtual void handleEvent();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; };
};
#endif

