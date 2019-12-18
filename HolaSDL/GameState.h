#ifndef GAMESTATE_H_
#define GAMESTATE_H_

class Game;
#include <list>
#include "ArrowsGameObject.h"
#include "EventHandler.h"
#include "SDLGameObject.h"

class GameState
{
protected:
	list<GameObject*> objects;
	list<EventHandler*> eventHandler;
	Game* game;
public:
	GameState(Game* game);
	~GameState();
	virtual void update();
	virtual void render();
	virtual void handleEvent(SDL_Event& event);
	virtual std::string getStateID() const = 0;
	virtual Game* giveMeGame() { return game; };
};
#endif

