#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include "Bow.h"
#include "Arrow.h";
#include <iostream>
//#include <vector>

typedef unsigned int uint;

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 3;

class Game {
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	// uint winWidth, winHeight; // También podrían estar aquí
	Bow* bow = nullptr;
	
	bool exit = false;
	Texture* textures[NUM_TEXTURES];
public:
	Game();
	~Game();
	void run();
	void render() const;
	//void handleEvents();
	void update();
};