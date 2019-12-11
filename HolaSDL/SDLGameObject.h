#ifndef SDLGAMEOBJECT_H_
#define SDLGAMEOBJECT_H_

#include "GameObject.h";
#include "Vector2D.h";
#include "Texture.h";
class GameState;

class SDLGameObject: public GameObject
{
protected:
	Point2D pos;
	uint w, h;
	Texture* textura;
	GameState* state;
	SDLGameObject(Point2D pos, uint w, uint h, Texture* texturaNormal, GameState* state);
public:
	virtual void render();
	virtual void update();
	virtual void handleEvents(SDL_Event event);
	virtual SDL_Rect getDestRect();
	virtual SDL_Rect getCollisionRect();
};
#endif

