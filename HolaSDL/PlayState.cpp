#include "PlayState.h"

PlayState::PlayState(list<GameObject*> _escenario, list<EventHandler*> _eventos, Game* _game) :GameState(_escenario, _eventos, _game) {};

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	// nothing for now
}
void PlayState::render()
{
	// nothing for now
}
void PlayState::handleEvent() {

}
bool PlayState::onEnter()
{
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";
	return true;
}