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
public:
	string currentState();
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();

	void update();
	void render();
};
#endif

