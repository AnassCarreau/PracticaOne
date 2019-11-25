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

typedef unsigned int uint;

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 9;
const uint NUM_Lvl = 6;

const uint NUM_BUTTERFLYS = 10;

struct Lvl
{
	string filename;
	int numFlecha;
	int numMariposas;
	Vector2D velocidadglobos;
	Vector2D velocidadMariposas;
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
		int level=-1;
		int puntuacion=0;
		int flechas = 20;
		Texture* textures[NUM_TEXTURES];
		Texture* fondo;
		double timecharge = 0;
		double timeshoot=0;
		Scoreboard* scoreboard;

		list <EventHandler*> eventHandler;
		list<GameObject*> objectsToErase;
		list<Arrow*> arrows;

		list<GameObject*>objects;
	

		Scores score;
		uint32_t startBaloonTime=0, frameBaloonTime=0; //variables para el control del tiempo
		int points = 0;
		Lvl niveles[NUM_Lvl] = { {"..\\images\\bg1.png", 10, 10,Vector2D(1,0),Vector2D(1,1)},{"..\\images\\bg_spring_trees_1.png", 1, 1,Vector2D(1,0),Vector2D(1,1)},{"..\\images\\Cartoon_Forest_BG_01.png", 10, 10,Vector2D(1,0),Vector2D(1,1)}
			,{"..\\images\\Cartoon_Forest_BG_02.png", 10, 10,Vector2D(1,0),Vector2D(1,1)},{"..\\images\\Cartoon_Forest_BG_03.png", 10, 10,Vector2D(1,0),Vector2D(1,1)}, {"..\\images\\Cartoon_Forest_BG_04.png", 10, 10,Vector2D(1,0),Vector2D(1,1)} };

		ImagenesAtributos imags[NUM_TEXTURES] = {{"..\\images\\Bow2.png", 1, 1},{"..\\images\\balloons.png", 7, 6},{"..\\images\\Bow1.png", 1, 1},{"..\\images\\Arrow1.png",1,1},{"..\\images\\Arrow2.png",1,1},{"..\\images\\digits1.png",1,10},{"..\\images\\butterfly2.png",4,10},{"..\\images\\rewards.png",10,8} ,{"..\\images\\bubble.png",1,1} };
	public:
		Game();
		~Game();
		void run();
		void render() const;
		void handleEvents();
		void update();
		void CargaFlecha();
		void DisparaFlecha(Point2D pos);
		bool OnCollisionEnter(SDL_Rect* rect,list<GameObject*>::iterator it);
		void generateBalloons();
		void AddPoints(int points,int hits);
		void KillObject(list<GameObject*>::iterator it);
		void CreateButterflys();
		void CreateReward(Point2D pos);
		void NewLvl();
};
#endif