#include "PauseState.h"
#include "checkML.h"

const std::string PauseState::s_pauseID = "PAUSE";

PauseState::PauseState(Game* game):GameState(game){
	saveButton = new MenuButton(Point2D(300, 100), 100, 100, game->GetTexture(13), this, SaveCallback);
	menuButton = new MenuButton(Point2D(300, 250), 100, 100, game->GetTexture(12), this, MenuCallback);
	continuePlayButton = new MenuButton(Point2D(300, 400), 100, 100, game->GetTexture(9), this, ContinuePlayingCallback);
	objects.push_back(saveButton);
	objects.push_back(menuButton);
	objects.push_back(continuePlayButton);
	eventHandler.push_back(saveButton);
	eventHandler.push_back(menuButton);
	eventHandler.push_back(continuePlayButton);
}


