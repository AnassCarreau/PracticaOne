#ifndef MENUBUTTON_H_
#define MENUBUTTON_H_

#include "SDLGameObject.h"
#include "Game.h"

using CallBackOnClick = void(Game* game);

class MenuButton: public SDLGameObject
{
private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
	button_state currentframe;
public:
	virtual void render();
	virtual void update();
	virtual void handleEvents(SDL_Event event);
};
#endif

