#ifndef GAMEH
#define GAMEH

#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include "Balloon.h"
#include "Bow.h"
#include "Arrow.h"
#include <vector>
typedef unsigned int uint;

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 5;
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
	vector<Arrow*> arrows;
	vector<Balloon*> balloons;
	ImagenesAtributos imags[NUM_TEXTURES] = { {"..\\images\\bg1.png", 1, 1},{"..\\images\\Bow2.png", 1, 1},{"..\\images\\balloons.png", 7, 6},{"..\\images\\Bow1.png", 1, 1},{"..\\images\\Arrow1.png",1,1} };
public:
	Game();
	~Game();
	void run();
	void render() const;
	void handleEvents();
	void update();
	void CargaFlecha(Point2D pos,Arrow*flecha);
	void DisparaFlecha(Point2D pos);
	bool MiraChoques(SDL_Rect*rectBalloon);
	void generateBalloons();
};
#endif