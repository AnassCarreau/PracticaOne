#include "MainMenuState.h"

const std::string MainMenuState::s_menuID = "MENU";

void MainMenuState::update()
{
	// nothing for now
}
void MainMenuState::render()
{
	// nothing for now
}
void MainMenuState::handleEvent() {

}
bool MainMenuState::onEnter()
{
	std::cout << "entering MainMenuState\n";
	return true;
}
bool MainMenuState::onExit()
{
	std::cout << "exiting MainMenuState\n";
	return true;
}