#include "GameStateMachine.h"


string GameStateMachine::currentState()
{
	return states.top()->getStateID();
}
void GameStateMachine::pushState(GameState* pState)
{
	states.push(pState);
	states.top()->onEnter();
}

void GameStateMachine::popState()
{
	if (!states.empty())
	{
		if (states.top()->onExit())
		{
			delete states.top();
			states.pop();
		}
	}
}

void GameStateMachine::changeState(GameState* pState)
{
	if (!states.empty())
	{
		if (states.top()->getStateID() == pState->getStateID())
		{
			return; // do nothing
		}
		if (states.top()->onExit())
		{
			delete states.top();
			states.pop();
		}
	}
	states.push(pState);
	// initialise it
	states.top()->onEnter();
}

void GameStateMachine::update()
{
	if (!states.empty())
	{
		states.top()->update();
	}
}

void GameStateMachine::render()
{
	if (!states.empty())
	{
		states.top()->render();
	}
}
