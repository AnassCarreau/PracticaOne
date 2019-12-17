#include "PauseState.h"

const std::string PauseState::s_pauseID = "PAUSE";

PauseState::PauseState(Game* game):GameState(game){
	saveButton = new MenuButton(Point2D(300, 100), 200, 100, game->GetTexture(13), this, SaveCallback);
	menuButton = new MenuButton(Point2D(300, 250), 200, 100, game->GetTexture(12), this, MenuCallback);
	objects.push_back(saveButton);
	objects.push_back(menuButton);
	eventHandler.push_back(saveButton);
	eventHandler.push_back(menuButton);
}
void PauseState::update()
{
	saveButton->update();
	menuButton->update();
}

void PauseState::render()
{
	saveButton->render();
	menuButton->render();
}

void PauseState::handleEvent(SDL_Event& event) {
	saveButton->handleEvent(event);
	menuButton->handleEvent(event);
}