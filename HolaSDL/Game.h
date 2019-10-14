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
struct ImagenesAtributos {
	string filename;
	uint nRows, nCols;
};

class Game {
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	// uint winWidth, winHeight; // También podrían estar aquí
	Bow* bow = nullptr;
	ImagenesAtributos imags[NUM_TEXTURES] = { {"..\\images\\bg1.png", 1, 1},{"..\\images\\Bow2.png", 1, 1},{"..\\images\\balloons.png", 7, 6} };
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