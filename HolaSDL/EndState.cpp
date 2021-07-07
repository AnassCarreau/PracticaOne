#include "EndState.h"
#include <iostream>
#include "checkML.h"

const std::string EndState::s_endID = "END";

EndState::EndState(Game* game) : GameState(game) {
	exitButton = new MenuButton(Point2D(300, 400), 100, 100, game->GetTexture(14), this, ExitCallback);
	menuButton = new MenuButton(Point2D(300, 250), 100, 100, game->GetTexture(12), this, MenuCallback);
	objects.push_back(exitButton);
	eventHandler.push_back(exitButton);
	objects.push_back(menuButton);
	eventHandler.push_back(menuButton);
}
