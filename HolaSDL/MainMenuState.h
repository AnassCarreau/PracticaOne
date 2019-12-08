#ifndef MAINMENUSTATE_H_
#define MAINMENUSTATE_H_

#include "MenuButton.h"
#include "GameState.h"

class MainMenuState: public GameState
{
private:
	static const std::string s_menuID;
public:
	virtual void update();
	virtual void render();
	virtual void handleEvent();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; };
};
#endif

