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
	void pushState();
	void changeState();
	void popState();
};
#endif

