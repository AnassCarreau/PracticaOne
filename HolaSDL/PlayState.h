#ifndef PLAYSTATE_H_
#define PLAYSTATE_H_

#include "GameState.h"
#include "checkML.h"
#include "Balloon.h"
#include "Scores.h"
#include "Bow.h"
#include "Arrow.h"
#include "Butterfly.h";
#include "Scoreboard.h"
#include "Reward.h"
#include "GiveMeArrows.h"
#include "BigArrows.h"
#include "FileNotFoundError.h"
class FileFormatError;
#include "SDLError.h"
#include "MenuButton.h"
#include <string>

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


class PlayState:public GameState
{
protected:
	//variables de game que usaremos para el estado play
	MenuButton* pauseButton;
	bool cargar;
	int level = -1;
	int puntuacion = 0;
	uint NUM_BUTTERFLYS;
	uint NUM_FLECHAS;
	Texture* fondo;
	double timecharge = 0;
	double timeshoot = 0;
	int arrowsSize = 1;
	Scoreboard* scoreboard;
	struct MinMaxValue VEL_BAL;
	struct MinMaxValue VEL_BUT;
	list<GameObject*> objectsToErase;
	list<Arrow*> arrows;


	Scores score;
	uint32_t startBaloonTime = 0, frameBaloonTime = 0; //variables para el control del tiempo
	Lvl niveles[NUM_Lvl] = {
	{"..\\images\\bg1.png", 10, 3, 0,5,2,4},
	{"..\\images\\bg_spring_trees_1.png", 11, 4,1,5,2,4},
	{"..\\images\\Cartoon_Forest_BG_01.png", 12, 8,2,5,2,4},
	{"..\\images\\Cartoon_Forest_BG_02.png", 13, 12,3,6,2,4},
	{"..\\images\\Cartoon_Forest_BG_03.png", 14, 15,3,7,2,4},
	{"..\\images\\Cartoon_Forest_BG_04.png", 15, 20,3,8,2,4}
	};
	//id del estado play
	static const std::string s_playID;
public:
	PlayState(Game* game, bool cargar);
	~PlayState();
	virtual void update();
	virtual void render();
	virtual std::string getStateID() const { return s_playID; };
	void CargaFlecha();
	void DisparaFlecha(Point2D pos);
	bool OnCollisionEnter(SDL_Rect rect, list<GameObject*>::iterator it);
	void generateBalloons();
	void AddPoints(int points, int hits);
	void KillObject(list<GameObject*>::iterator it);
	void CreateButterflys();
	void CreateReward(Point2D pos);
	void NewLvl(int level);
	void saveToFile(ofstream& output);
	void loadFroamFile(ifstream& input);
	void AddArrows(int arrows);
	void ArrowSize(double proporcion);
};
#endif

