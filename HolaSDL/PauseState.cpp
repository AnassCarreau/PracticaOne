#include "PauseState.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::update()
{
	// nothing for now
}
void PauseState::render()
{
	// nothing for now
}

void PauseState::handleEvent() {

}

bool PauseState::onEnter()
{
	std::cout << "entering PauseState\n";
	return true;
}
bool PauseState::onExit()
{
	std::cout << "exiting PauseState\n";
	return true;
}