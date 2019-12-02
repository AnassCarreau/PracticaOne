#include "Game.h"
#include "checkML.h"
#include <string>
#include <iostream>
#include <random>
#include <vector>
#include <math.h>
using namespace std;
typedef unsigned int uint;

Game::Game() {
	//Primero inicializamos SDL
	
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Practica 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw SDLError();
	
	//Creacion de las texturas
	for (uint i = 0; i < NUM_TEXTURES; i++) {
	
		textures[i] = new Texture(renderer, imags[i].filename, imags[i].nRows, imags[i].nCols);
		
	}
	scoreboard = new Scoreboard(Point2D(300, 0), 25, 35, textures[5], textures[4], NUM_FLECHAS);
	objects.push_back(scoreboard);
	int n;
	ifstream input;
	cout << "Si quieres cargar una partida pulsa '1', si quieres empezar de cero pulsa cualquier numero:" << endl;
	cin >> n;
	if (n == 1) {
		loadFroamFile(input);
	}
	else
	{
		Bow* arco = new Bow(Point2D(0, 100), 80, 80, Vector2D(0, 10), textures[0], textures[2], this);
		objects.push_back(arco);
		arco->setItList(--objects.end());
		eventHandler.push_back(arco);
		NewLvl(0);

	}
	run();	
}
//metodo de destruccion de basura
Game::~Game() {
	for (uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];
	auto it = objects.begin();
	while (it!=objects.end())
	{
		objects.remove(*it);
		it = objects.begin();
	}
	
	objectsToErase.clear();
	arrows.clear();
	objects.clear();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
//metodo principal del juego con estructura->eventos->actualizar->renderizar
void Game::run() {
	
	uint32_t startTime, frameTime; //variables para el control del tiempo
	startTime = SDL_GetTicks(); //tiempo inicial en milisegundos
	startBaloonTime = SDL_GetTicks();
	const int FRAME_RATE = 20 ; //20fps
	while (!exit && NUM_BUTTERFLYS!=0 && level<6 && NUM_FLECHAS!=0) { 
		handleEvents();
		//actualizamos el juego cada Frame_Rate
		frameTime = SDL_GetTicks() - startTime;
		if (frameTime >= FRAME_RATE) {
			update();
			startTime = SDL_GetTicks();
		}		
		render();
		
	}
	int g;
	ofstream output;
	cout << "Si quieres guardar la partida pulsa '2'" << endl;
	cin >> g;
	if (g == 2) saveToFile(output);
	//else throw ArrowsError("Ese no es el numero 2, no se ha podido guardar la partida");
}
//metodo que actualiza el estado del juego
void Game::update() {
	
	generateBalloons();
	
	for (auto et = objects.begin(); et != objects.end(); ++et) {
		(*et)->update();
	}	
	for (auto it = objectsToErase.begin(); it != objectsToErase.end(); ++it) {
		objects.remove(*it);
		eventHandler.remove(dynamic_cast<EventHandler*>(*it));
		arrows.remove(dynamic_cast<Arrow*>(*it));

		
	}	
	objectsToErase.clear();
}
//metodo que renderiza todos los objetos del juego
void Game::render() const {
	//
	//limpiamos
	SDL_RenderClear(renderer);
	//renderizado del fondo
	SDL_Rect bk;
	bk = { 0,0,WIN_WIDTH,WIN_HEIGHT };
	
	fondo->render(bk, SDL_FLIP_NONE);
	//renderizado arco
	for (auto it = objects.begin(); it != objects.end(); ++it){
	
		(*it)->render();
	}
	
	SDL_RenderPresent(renderer);
}
//metodo que controla los eventos del juego
void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		else {
			
			for (auto it = eventHandler.begin(); it != eventHandler.end(); ++it) {

				(*it)->handleEvent(event);
			}
		}
	}
}
//metodo que genera globo cada 2 segundos
void Game::generateBalloons() {
	
	const int FRAME_RATEGLOB = 500; // cada dos segundos generamos un globo
	frameBaloonTime = SDL_GetTicks() - startBaloonTime;
	if (frameBaloonTime >= FRAME_RATEGLOB) {
		int h =  rand() % 320 + 400;
		int color = rand() % 7;
		double velocidad = rand() % (int)VEL_BUT.max + VEL_BUT.min;
		Balloon* globo=new  Balloon(Point2D{ (double)h,600 }, 80, 80, Vector2D(0, -velocidad), textures[1], false, 0, this, color);
		auto it = objects.insert(objects.end(), globo);
		globo->setItList(it);
		
		startBaloonTime = SDL_GetTicks();
	}
	
}
//metodo que coge el tiempo de carga de la flecha
void Game::CargaFlecha()
{
	timecharge = SDL_GetTicks();
}
//metodo para disparar la flecha
void Game::DisparaFlecha(Point2D pos) {
	//le llega a dispara flecha una flecha 
	/*auto it=object.insert(object.end(),arrow)
	arrows->setit(it)
	*/
	if (NUM_FLECHAS !=0)
	{
		timeshoot = SDL_GetTicks();
		timecharge =(timeshoot- timecharge)/1000;
		if (timecharge>10)
		{
			timecharge = 10;
		}
		Arrow* flecha = new Arrow(Vector2D(timecharge + 4, 0), textures[3], this, Point2D(pos.getX() + 20, pos.getY() + 30), 90+arrowsSize, 20+arrowsSize);
		auto it = objects.insert(objects.end(), flecha);
		arrows.push_back(flecha);
		flecha->setItList(it);
		NUM_FLECHAS--;

		/*objects.push_back(flecha);
		flecha->setItList(--objects.end());*/

		scoreboard->Arrows(NUM_FLECHAS);
	}
}
//metodo para añadir puntos
void Game::AddPoints(int pointsadd,int hits)
{
	if (hits <= 0) {
		puntuacion += pointsadd;
	}
	else {
		puntuacion += pointsadd + sqrt(hits - 1) * pointsadd;
	}
	if (puntuacion>=0)
	{
		scoreboard->Puntuacion(puntuacion);

	}
	if (puntuacion/100>level)
	{
		level++;
		NewLvl(level);
	}
}



//metodo que mira si alguna flecha ha tocado con un globo
bool Game::OnCollisionEnter(SDL_Rect rect,list<GameObject*>::iterator collider) {
	
	for (auto it = arrows.begin(); it != arrows.end(); ++it)
	{
		if (SDL_HasIntersection(&rect, &(*it)->getCollisionRect()))
		{
			if (dynamic_cast<Balloon*>(*collider) != nullptr)
			{
				AddPoints(POINTS, (*it)->getHits());
				int estadistica = rand() % 1;
				if (estadistica == 0) {
					double y = (double)rect.y + rect.h;
					CreateReward(Point2D(rect.x, y));
				}
			}
			 else if (dynamic_cast<Butterfly*>(*collider) != nullptr)
			{
				AddPoints(-POINTS/2, 0);
				NUM_BUTTERFLYS--;
				
			}
			return true;
		}
	}
	return false;
}

void Game::KillObject(list<GameObject*>::iterator it) {

	objectsToErase.push_back(*it);
}

void Game::CreateButterflys() {
	int posiX, posiY;
		double velX, velY;
	for (uint j = 0; j < NUM_BUTTERFLYS; j++) {
		posiX = rand() %  600+ 100;
		posiY = rand() % 400 + 100;
		velX = rand() % (int)VEL_BUT.max - VEL_BUT.min;
		velY = rand() % (int)VEL_BUT.max - VEL_BUT.min;

		Butterfly* mariposa = new Butterfly(Point2D((double)posiX, (double)posiY), Vector2D(velX, velY), 60, 60, textures[6], this);
		auto it = objects.insert(objects.end(), mariposa);
		mariposa->setItList(it);
	}
}
void Game::CreateReward(Point2D pos)
{
	
		int color = rand() % 2;
		Reward* premio=nullptr;
		switch (color)
		{
		case 0: premio = new GiveMeArrows(pos, Vector2D(0, 0.1), 100, 70, textures[7], textures[8], this, color);
			break;
		case 1: premio = new BigArrows(pos, Vector2D(0, 0.1), 100, 70, textures[7], textures[8], this, color);
			break;
		
		}
		eventHandler.push_back(premio);
		auto et = objects.insert(objects.end(), premio);
		premio->setItList(et);
	
}

void Game::NewLvl(int _level)
{
	level = _level;
	fondo = new Texture(renderer, niveles[level].filename, 1, 1);
	for (auto it = objects.begin(); it != objects.end(); ++it) {
		if (dynamic_cast<Bow*>(*it) == nullptr && dynamic_cast<Scoreboard*>(*it) == nullptr)
		{
			objectsToErase.push_back(*it);
			eventHandler.remove(dynamic_cast<Reward*>(*it));
		}
		
	}
	arrows.clear();
	arrowsSize = 0;
	NUM_FLECHAS = niveles[level].numFlecha;
	NUM_BUTTERFLYS = niveles[level].numMariposas;
	VEL_BAL = niveles[level].velBal;
	VEL_BUT = niveles[level].velBut;
	scoreboard->Arrows(NUM_FLECHAS);
	CreateButterflys();
}

void Game::saveToFile(ofstream& output) {
	//abrimos el archivo
	output.open("guardados.txt");
	//si no se abre lanzamos excepcion
	if (!output.is_open()) throw FileNotFoundError("No se encuentra el archivo");
	//si se puede abrir guardamos la partida
	else {
		output << level << endl;
		output << puntuacion << endl;
		output << NUM_FLECHAS << endl;
		int objetos = objects.size();
		output << objetos << endl;
		for (auto it = ++objects.begin(); it != objects.end(); ++it) {
			dynamic_cast<ArrowsGameObject*>(*it)->saveToFile(output);
		}
	}
	output.close();

}

void Game::loadFroamFile(ifstream& input) {

	//abrimos el archivo
	input.open("guardados.txt");
	//si no se puede abrir lanzamos una excepcion
	if (!input.is_open()) throw FileNotFoundError("No se encuentra el archivo");
	//si se abre cargamos el archivo
	else {
		input >> level;
		fondo = new Texture(renderer, niveles[level].filename, 1, 1);
		VEL_BAL = niveles[level].velBal;
		VEL_BUT = niveles[level].velBut;
		input >> puntuacion;
		scoreboard->Puntuacion(puntuacion);
		input >> NUM_FLECHAS;
		scoreboard->Arrows(NUM_FLECHAS);
		int obj;
		int color;
		input >> obj;
		string line;
		for (int i = 0; i < obj; i++) {
			input >> line;
			//falta que cada objeto sepa cual es su textura
			if (line == "Mariposa")objects.push_back(new Butterfly(Point2D(NULL, NULL), Vector2D(NULL, NULL), 20, 20, textures[6], this));
			else if (line == "Globo")objects.push_back(new Balloon(Point2D(NULL, NULL), 20, 20, Vector2D(NULL, NULL), textures[1], false, 0, this, NULL));
			else if (line == "Flecha")
			{
				objects.push_back(new Arrow(Vector2D(NULL, NULL), textures[3], this, Point2D(NULL, NULL), 20, 20));
				arrows.push_back(dynamic_cast<Arrow*>(objects.back()));
			}
			else if (line == "Arco") {
				objects.push_back(new Bow(Point2D(0, 0), 20, 20, Vector2D(0, 0), textures[0], textures[2], this));
				eventHandler.push_back(dynamic_cast<EventHandler*>(objects.back()));
			}
			else if (line == "Premio") {
				
				input >> color;
				switch (color)
				{
					case 0:
						objects.push_back(new GiveMeArrows(Point2D(0, 0), Vector2D(0, 0), 20, 20, textures[7], textures[8], this, color));
						break;
					case 1:
						objects.push_back(new BigArrows(Point2D(0, 0), Vector2D(0, 0), 20, 20, textures[7], textures[8], this, color));
						break;
					
				}
				eventHandler.push_back(dynamic_cast<EventHandler*>(objects.back()));
			}
			else
			{
				throw FileFormatError("Formato de archivo incorrecto");
			}
			dynamic_cast<ArrowsGameObject*>(objects.back())->loadFromFile(input);
			dynamic_cast<ArrowsGameObject*>(objects.back())->setItList(--objects.end());
		}
	}
	input.close();
}
	
 void Game::AddArrows(int arrows)
 {
	 NUM_FLECHAS += arrows;
	 scoreboard->Arrows(NUM_FLECHAS);
 }
 void Game::ArrowSize(double prop)
 {
	 arrowsSize += prop;
 }
 
