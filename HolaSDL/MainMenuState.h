#ifndef MAINMENUSTATE_H_
#define MAINMENUSTATE_H_

#include "GameState.h";
#include "MenuButton.h";
#include <string>;

class MainMenuState: public GameState
{
private:
	static const std::string s_menuID;
	MenuButton* playButton;
	MenuButton* loadButton;
	MenuButton* exitButton;

public:
	MainMenuState(Game* game);
	virtual std::string getStateID() const { return s_menuID; };
};
#endif

