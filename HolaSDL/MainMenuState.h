#ifndef MAINMENUSTATE_H_
#define MAINMENUSTATE_H_

//#include "MenuButton.h"
#include <string>
#include "GameState.h"

class MainMenuState: public GameState
{
private:
	static const std::string s_menuID;
	static void s_menuToPlay();
	static void s_exitFromMenu();
public:
	virtual void update();
	virtual void render();
	virtual void handleEvent();
	/*virtual bool onEnter();
	virtual bool onExit();*/

	virtual std::string getStateID() const { return s_menuID; };
};
#endif

