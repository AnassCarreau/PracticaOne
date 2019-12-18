#ifndef PAUSESTATE_H_
#define PAUSESTATE_H_

#include "MenuButton.h"
#include "GameState.h"
class PauseState:public GameState
{
private:
	static const std::string s_pauseID;
	MenuButton* saveButton;
	MenuButton* menuButton;
	MenuButton* continuePlayButton;
public:
	PauseState(Game* game);
	~PauseState();
	virtual std::string getStateID() const { return s_pauseID; };
};
#endif

