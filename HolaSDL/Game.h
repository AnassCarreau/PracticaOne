#ifndef GAMEH
#define GAMEH

#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include "Balloon.h"
#include "Bow.h"
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
	bool exit = false;
	int puntuacion;
	int flechas;
	Texture* textures[NUM_TEXTURES];
	// uint winWidth, winHeight; // También podrían estar aquí
	Bow* bow = nullptr; 
	Balloon* globo = nullptr;
	Balloon* globos[10];

	ImagenesAtributos imags[NUM_TEXTURES] = { {"..\\images\\bg1.png", 1, 1},{"..\\images\\Bow2.png", 1, 1},{"..\\images\\balloons.png", 7, 6} };
public:
	Game();
	~Game();
	void run();
	void render() const;
	void handleEvents();
	void update();
};
#endif