#ifndef PAUSESTATE_H_
#define PAUSESTATE_H_

#include "MenuButton.h"
#include "GameState.h"
class PauseState:public GameState
{
private:
	static const std::string s_pauseID;
	static void s_pauseToMain();
	static void s_resumePlay();
	list<GameObject*> m_gameObjects;

public:
	virtual void update();
	virtual void render();
	virtual void handleEvent();
	//virtual bool onEnter();
	//virtual bool onExit();

	virtual std::string getStateID() const { return s_pauseID; };
};
#endif

