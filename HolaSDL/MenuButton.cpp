#include "MenuButton.h"
#include "SDLGameObject.h"
MenuButton::MenuButton(Point2D pos, uint w, uint h, Texture* Button, GameState* state, CallBackOnClick* _call)
	: SDLGameObject(pos, w, h, Button, state) { callbackbutton = _call; }

void PlayCallback(Game* game) {
	game->Play();
}

void PauseCallback(Game* game) {
	game->Pause();
}

void ExitCallback(Game* game) {
	game->Exit();
}

void LoadCallback(Game* game) {
	game->Load();
}

void SaveCallback(Game* game) {
	game->Save();
}

void MenuCallback(Game* game) {
	game->Menu();
}

void MenuButton::update() {
	
}

void MenuButton::render() {
	SDLGameObject::render();
}

void MenuButton::handleEvent(SDL_Event& event) {

	if ((event.type == SDL_MOUSEBUTTONUP) && (event.button.button == SDL_BUTTON_LEFT)) {
		SDL_Point mousePoint = { event.button.x, event.button.y };
		
		if (SDL_PointInRect(&mousePoint, &getDestRect())) {
			callbackbutton(state->giveMeGame());
		}
	}
}