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
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void handleEvent(SDL_Event& event) = 0;
	/*virtual bool onEnter() = 0;
	virtual bool onExit() = 0;*/
	virtual std::string getStateID() const = 0;
	virtual Game* giveMeGame() { return game; };
};
#endif

