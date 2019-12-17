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
	~MainMenuState();
	virtual void update();
	virtual void render();
	virtual void handleEvent(SDL_Event& event);
	/*virtual bool onEnter();
	virtual bool onExit();*/

	virtual std::string getStateID() const { return s_menuID; };
};
#endif

