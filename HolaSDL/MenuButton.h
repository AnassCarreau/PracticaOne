#ifndef MENUBUTTON_H_
#define MENUBUTTON_H_

#include "SDLGameObject.h"
using CallBackOnClick = void(Game* game);

class MenuButton: public SDLGameObject
{
private:
	Texture* textura;
public:
	void render();
	void update();
	void handleEvent();
};
#endif

