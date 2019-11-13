#ifndef GAMEH
#define GAMEH

#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include "Balloon.h"
#include "Scores.h"
#include "Bow.h"
#include "Arrow.h"
#include <vector>
#include <list>
#include "Scoreboard.h"
typedef unsigned int uint;

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 7;
struct ImagenesAtributos {
	string filename;
	uint nRows, nCols;
};

class Game {
private:
	vector<ArrowsGameObject*>go;
	
	//ArrowsGameObject* go[5];
	//go = new Bow();
	//go[1] = new Arrow();
	//go[2] = new Balloon();
	//go[3] = new Butterfly();
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool exit = false;
	int level=0;
	int puntuacion=0;
	int flechas=0;
	Texture* textures[NUM_TEXTURES];
	Bow* bow = nullptr;
	double timecharge = 0;
	double timeshoot=0;
	vector<Arrow*> arrows;
	vector<Balloon*> balloons;
	Scoreboard* scoreboard;
	

	/*list <EventHandler*> eventHandler;
	list<GameObject*> objectsToErase;
	list<Arrow*> arrowss;
	list<GameObject*>objects;*/
	/*void update()
	for(..ob:objects)ob->update()
	for (..ob::objectstoerase){
	delete ob
	objects.erase(ob.setit)
	o
	objects.remove(ob)}
	objectstoerase.clear()
	
	*/

	Scores score;
	uint32_t startBaloonTime=0, frameBaloonTime=0; //variables para el control del tiempo
	int points = 0;
	const int POINT_ADD = 10;
	/*list<GameObject*>::iterator it;it=objects.begin()
	while(it!=objects.end())*it->update();++it; 
	*/
	

	ImagenesAtributos imags[NUM_TEXTURES] = { {"..\\images\\bg1.png", 1, 1},{"..\\images\\Bow2.png", 1, 1},{"..\\images\\balloons.png", 7, 6},{"..\\images\\Bow1.png", 1, 1},{"..\\images\\Arrow1.png",1,1},{"..\\images\\Arrow2.png",1,1},{"..\\images\\digits1.png",1,10} };
public:
	Game();
	~Game();
	void run();
	void render() const;
	void handleEvents();
	void update();
	void CargaFlecha();
	void DisparaFlecha(Point2D pos);
	bool OnCollisionEnter(SDL_Rect*rectBalloon);
	void generateBalloons();
	void AddPoints();
	//void KillObject(GameObject* object);
	//void NewLvl();
};
#endif