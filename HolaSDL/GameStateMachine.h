#ifndef GAMESTATEMACHINE_H_
#define GAMESTATEMACHINE_H_

#include <string>
using namespace std;

class GameStateMachine
{
private:
	//stack<GameState*>;
public:
	string currentState();
	void pushState();
	void changeState();
	void popState();
};
#endif

