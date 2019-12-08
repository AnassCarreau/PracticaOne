#ifndef PAUSESTATE_H_
#define PAUSESTATE_H_

#include "MenuButton.h"

class PauseState
{
private:
	static const std::string s_pauseID;
public:
	virtual void update();
	virtual void render();
	virtual void handleEvent();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_pauseID; };
};
#endif

