#ifndef GAMESTATEMACHINE_H_
#define GAMESTATEMACHINE_H_

#include <string>
#include <stack>
#include "GameState.h"

using namespace std;

class GameStateMachine
{
private:
	stack<GameState*> states;
	Game* game;
public:
	GameStateMachine(Game* game);
	GameState* currentState();
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();

	void update();
	void render();
	void handleEvents(SDL_Event event);
};
#endif

