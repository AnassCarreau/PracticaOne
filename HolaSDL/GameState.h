#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "Game.h"

class GameState
{
private:


	Game* game;
public:
	//GameState(list<GameObject*> escenario, list<EventHandler*> eventos, Game* game);
	list<GameObject*> escenario;
	list<EventHandler*> eventos;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void handleEvent() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual std::string getStateID() const = 0;
};
#endif

