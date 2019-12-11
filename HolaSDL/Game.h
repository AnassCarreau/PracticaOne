#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include "FileNotFoundError.h"
#include "FileFormatError.h"
#include "SDLError.h"
#include "GameStateMachine.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "EndState.h"

typedef unsigned int uint;

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 9;
 
struct ImagenesAtributos {
	string filename;
	uint nRows, nCols;
};



class Game {
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	GameStateMachine* gameStateMachine;
	bool exit = false;
	Texture* textures[NUM_TEXTURES];
	ImagenesAtributos imags[NUM_TEXTURES] = { {"..\\images\\Bow2.png", 1, 1},{"..\\images\\balloons.png", 7, 6},{"..\\images\\Bow1.png", 1, 1},{"..\\images\\Arrow1.png",1,1},{"..\\images\\Arrow2.png",1,1},{"..\\images\\digits1.png",1,10},{"..\\images\\butterfly2.png",4,10},{"..\\images\\rewards.png",10,8} ,{"..\\images\\bubble.png",1,1} };
public:
	Game();
	~Game();
	void run();
	void render() const;
	void handleEvents();
	void update();
	Texture* GetTexture(int index);
	SDL_Renderer* GetRenderer();
	GameStateMachine* getStateMachine() { return gameStateMachine; };
};
#endif