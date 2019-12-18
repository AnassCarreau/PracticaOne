#include "GameState.h"
#include "checkML.h"

GameState::GameState(Game* _game) : game(_game) {};

GameState::~GameState() {
	for (auto it = objects.begin(); it != objects.end(); it++) {
		delete* it;
		objects.erase(it);
	}
}

void GameState::update() {
	for (auto it = objects.begin(); it != objects.end(); it++) {
		(*it)->update();
	}
}

void GameState::render() {
	for (auto it = objects.begin(); it != objects.end(); it++) {
		(*it)->render();
	}
}

void GameState::handleEvent(SDL_Event& event) {
	for (auto it = eventHandler.begin(); it != eventHandler.end(); it++) {
		(*it)->handleEvent(event);
	}
}
