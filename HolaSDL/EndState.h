#ifndef ENDSTATE_H_
#define ENDSTATE_H_

#include <string>
#include "GameState.h"

class EndState: public GameState
{
private:
	static const std::string s_endID;
public:
	virtual void update();
	virtual void render();
	virtual void handleEvent();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_endID; };
};
#endif

