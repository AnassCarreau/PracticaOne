#include "SDLGameObject.h"

SDLGameObject::SDLGameObject(Point2D _pos, uint _w, uint _h, Texture* _textura, GameState* _state) : pos(_pos), w(_w), h(_h),textura(_textura), state(_state){}

void SDLGameObject::update() {

}

void SDLGameObject::render() {
	textura->render(getDestRect(), SDL_FLIP_NONE);
}

void SDLGameObject::handleEvents(SDL_Event event) {
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		
	}
}

SDL_Rect SDLGameObject::getDestRect() {
	return SDL_Rect{ (int)pos.getX(),  (int)pos.getY(),(int)w,(int)h };
}

SDL_Rect SDLGameObject::getCollisionRect() {
	int pointX = pos.getX() + w / 2;
	int pointY = pos.getY() + h / 2;
	int arrowwidth = w / 2;
	int arrowheight = h / 2;
	return SDL_Rect{ pointX, pointY, arrowwidth,arrowheight };
}