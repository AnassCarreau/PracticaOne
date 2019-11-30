#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include "Balloon.h"
#include "Scores.h"
#include "Bow.h"
#include "Arrow.h"
#include "Butterfly.h";
#include <list>
#include "Scoreboard.h"
#include "Reward.h"
#include "GiveMeArrows.h"
#include "BigArrows.h"
#include "FileNotFoundError.h"
#include "FileFormatError.h"
#include "SDLError.h"

typedef unsigned int uint;

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 9;
const uint NUM_Lvl = 6;

 
 struct MinMaxValue
 {
	 double min;
	 double max;

 };
struct Lvl
{
	string filename;
	int numFlecha;
	int numMariposas;
	struct MinMaxValue velBal;
	struct MinMaxValue velBut;
};
struct ImagenesAtributos {
	string filename;
	uint nRows, nCols;
};



class Game {
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool exit = false;
	int level = -1;
	int puntuacion = 0;
	uint NUM_BUTTERFLYS;
	uint NUM_FLECHAS;
	Texture* textures[NUM_TEXTURES];
	Texture* fondo;
	double timecharge = 0;
	double timeshoot = 0;
	int arrowsSize = 1;
	Scoreboard* scoreboard;
	struct MinMaxValue VEL_BAL;
	struct MinMaxValue VEL_BUT;
	list <EventHandler*> eventHandler;
	list<GameObject*> objectsToErase;
	list<Arrow*> arrows;
	//Reward* premio[2]={new GiveMeArrows(),}
	list<GameObject*>objects;


	Scores score;
	uint32_t startBaloonTime = 0, frameBaloonTime = 0; //variables para el control del tiempo
	Lvl niveles[NUM_Lvl] = {
	{"..\\images\\bg1.png", 10, 10, 0.5,5,2,4},
	{"..\\images\\bg_spring_trees_1.png", 10, 2,0.5,5,2,4},
	{"..\\images\\Cartoon_Forest_BG_01.png", 10, 10,0.5,5,2,4},
	{"..\\images\\Cartoon_Forest_BG_02.png", 10, 10,0.5,5,2,4},
	{"..\\images\\Cartoon_Forest_BG_03.png", 10, 10,0.5,5,2,4},
	{"..\\images\\Cartoon_Forest_BG_04.png", 10, 10,0.5,5,2,4}
	};
	ImagenesAtributos imags[NUM_TEXTURES] = { {"..\\images\\Bow2.png", 1, 1},{"..\\images\\balloons.png", 7, 6},{"..\\images\\Bow1.png", 1, 1},{"..\\images\\Arrow1.png",1,1},{"..\\images\\Arrow2.png",1,1},{"..\\images\\digits1.png",1,10},{"..\\images\\butterfly2.png",4,10},{"..\\images\\rewards.png",10,8} ,{"..\\images\\bubble.png",1,1} };
public:
	Game();
	~Game();
	void run();
	void render() const;
	void handleEvents();
	void update();
	void CargaFlecha();
	void DisparaFlecha(Point2D pos);
	bool OnCollisionEnter(SDL_Rect* rect, list<GameObject*>::iterator it);
	void generateBalloons();
	void AddPoints(int points, int hits);
	void KillObject(list<GameObject*>::iterator it);
	void CreateButterflys();
	void CreateReward(Point2D pos);
	void NewLvl(int level);
	void saveToFile(ofstream& output);
	void loadFroamFile(ifstream& input);
	void AddArrows(int arrows);
	void ArrowSize(int proporcion);
};
#endif