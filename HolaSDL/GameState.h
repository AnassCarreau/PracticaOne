#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "Game.h"

class GameState
{
private:
	list<GameObject*> escenario;
	list<EventHandler*> eventos;
	Game* game;
public:
	GameState(list<GameObject*> escenario, list<EventHandler*> eventos, Game* game);
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void handleEvent() = 0;
};
#endif

