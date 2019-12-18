#include "MainMenuState.h";
#include "checkML.h"

const std::string MainMenuState::s_menuID = "MENU";
MainMenuState::MainMenuState(Game* game): GameState(game){
	//cargar texturas de botones del menu principal
	playButton = new MenuButton(Point2D(300, 100), 100, 100, game->GetTexture(9), this, PlayCallback);
	loadButton = new MenuButton(Point2D(300, 250), 100, 100, game->GetTexture(11), this, LoadCallback);
	exitButton = new MenuButton(Point2D(300, 400), 100, 100, game->GetTexture(14), this, ExitCallback);
	objects.push_back(playButton);
	objects.push_back(loadButton);
	objects.push_back(exitButton);
	eventHandler.push_back(playButton);
	eventHandler.push_back(loadButton);
	eventHandler.push_back(exitButton);
}
