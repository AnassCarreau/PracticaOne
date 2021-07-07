#ifndef MENUBUTTON_H_
#define MENUBUTTON_H_

class SDLGameObject;
#include "Game.h"
#include "EventHandler.h"

using CallBackOnClick = void(Game* game);
//callbacks para el menu principal
void PlayCallback(Game* game);
void LoadCallback(Game* game);
void ExitCallback(Game* game);
//callback para el juego
void PauseCallback(Game* game);
//callbacks para el menu pausa
void ContinuePlayingCallback(Game* game);
void SaveCallback(Game* game);
void MenuCallback(Game* game);


class MenuButton: public SDLGameObject, public EventHandler
{	
private:
	CallBackOnClick* callbackbutton;
public:
	MenuButton(Point2D pos, uint w, uint h, Texture* normalButton, GameState* state, CallBackOnClick* call);
	virtual void render();
	virtual void handleEvent(SDL_Event& event);
};
#endif

