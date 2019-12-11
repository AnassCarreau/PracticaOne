#ifndef ENDSTATE_H_
#define ENDSTATE_H_

#include <string>
#include "GameState.h"

class EndState: public GameState
{
private:
	static const std::string s_endID;
	static void s_gameOverToMain();
	static void s_restartPlay();
	//static const std::string s_gameOverID;
public:
	virtual void update();
	virtual void render();
	virtual void handleEvent();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_endID; };
};
#endif

