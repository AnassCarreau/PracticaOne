#ifndef ENDSTATE_H_
#define ENDSTATE_H_

#include <string>
#include "GameState.h"
#include "MenuButton.h"
class EndState: public GameState
{
private:
	static const std::string s_endID;
	MenuButton* exitButton;
	MenuButton* menuButton;
public:
	EndState(Game* game);
	virtual std::string getStateID() const { return s_endID; };
};
#endif

