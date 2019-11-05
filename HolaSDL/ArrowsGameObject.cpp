#include "ArrowsGameObject.h"

ArrowsGameObject::ArrowsGameObject(Point2D esqIzq, uint width, uint height, Vector2D vel, Texture* textura, Game* game)
	: pos(esqIzq), width(width), height(height), velocity(vel), textura(textura), game(game) {}