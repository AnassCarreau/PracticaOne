#include "EndState.h"
#include <iostream>

const std::string EndState::s_endID = "END";

EndState::EndState(Game* game) : GameState(game) {
	exitButton = new MenuButton(Point2D(300, 400), 200, 100, game->GetTexture(14), this, ExitCallback);
	menuButton = new MenuButton(Point2D(300, 250), 200, 100, game->GetTexture(12), this, MenuCallback);
	objects.push_back(exitButton);
	eventHandler.push_back(exitButton);
}
void EndState::update()
{
	exitButton->update();
	menuButton->update();
}
void EndState::render()
{
	exitButton->render();
	menuButton->render();
}
void EndState::handleEvent(SDL_Event& event) {
	exitButton->handleEvent(event);
	menuButton->handleEvent(event);
}