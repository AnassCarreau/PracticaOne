#ifndef MENUBUTTON_H_
#define MENUBUTTON_H_

#include "SDLGameObject.h"
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
	void (*m_callback)();
	bool m_bReleased;

	Texture* textura;
public:
	void render();
	virtual void update();
	void handleEvent();
	MenuButton(const LoaderParams* pParams,void (*callback));
	virtual void draw();
	virtual void clean();
};
#endif

