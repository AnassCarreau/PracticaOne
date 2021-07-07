#include "GameStateMachine.h"
#include "checkML.h"


GameStateMachine::GameStateMachine(Game* _game) : game(_game){}
GameState* GameStateMachine::currentState()
{
	return states.top();
}
void GameStateMachine::pushState(GameState* pState)
{
	states.push(pState);
}

void GameStateMachine::popState()
{
	if (!states.empty())
	{
		delete states.top();
		states.pop();
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
	}
	states.push(pState);
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

void GameStateMachine::handleEvents(SDL_Event event) {
	if (!states.empty())
	{
		states.top()->handleEvent(event);
	}
}
