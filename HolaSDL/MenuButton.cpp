#include "MenuButton.h"

void MenuButton::update() {
	/*if (SDL_GetMouseState == pos) {
		currentframe = MOUSE_OVER;
	}*/
}
void MenuButton::render() {
	SDLGameObject::render();
}
void MenuButton::handleEvents(SDL_Event event) {
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		currentframe = CLICKED;
	}
	else if (event.type == SDL_MOUSEBUTTONUP) {
		currentframe = MOUSE_OUT;
	}
}