#include "EndState.h"
#include <iostream>

const std::string EndState::s_endID = "END";

void EndState::update()
{
	// nothing for now
}
void EndState::render()
{
	// nothing for now
}
void EndState::handleEvent() {

}
bool EndState::onEnter()
{
	std::cout << "entering EndState\n";
	return true;
}
bool EndState::onExit()
{
	std::cout << "exiting EndState\n";
	return true;
}