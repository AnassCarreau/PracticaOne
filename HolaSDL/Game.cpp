#include "Game.h"
#include "checkML.h"
#include <string>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
typedef unsigned int uint;

Game::Game() {
	//Primero inicializamos SDL

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Practica 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw "Error loading the SDL window or renderer";

	//Creacion de las texturas
	for (uint i = 0; i < NUM_TEXTURES; i++) {
	
		textures[i] = new Texture(renderer, imags[i].filename, imags[i].nRows, imags[i].nCols);
		
	}
	//Creacion de los gameobjects (los globos y las flechas los generamos mediante un metodo que los genera en un vector)
	flechas = 10;
	Bow* arco = new Bow(Point2D(0, 100), 80, 80, Vector2D(0, 10), textures[1], textures[3], this);
	auto it=objects.insert(objects.end(),arco);
	arco->setItList(it);
	//creacion de las mariposas
	CreateButterflys();

	//eventHandler.push_back(arco);
	
	
	
	/*ArrowsGameObject* temp = new Arrow(Point2D(0, 0), textures[4], this, Vector2D(0, 10), 80, 80);
	objects.push_back(temp);
	auto it=--objects.end();
	temp->setItList(it);*/
	
	

	scoreboard = new Scoreboard(Point2D(300,0),25,35,textures[6],textures[5],flechas);
	
	run();	
}
//metodo de destruccion de basura
Game::~Game() {
	for (uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];
	delete scoreboard;
	scoreboard = nullptr;
	//delete bow;
	//bow = nullptr;
	/*for (int i = 0; i < arrows.size(); i++) {
		delete arrows[i];
		arrows[i] = nullptr;
	}
	for (int j = 0; j < balloons.size(); j++) {
		delete balloons[j];
		balloons[j] = nullptr;
	}*/ 
	//que cada objeto se destruya a si mismo 
	
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
	while (!exit) { 
		handleEvents();
		//actualizamos el juego cada Frame_Rate
		frameTime = SDL_GetTicks() - startTime;
		if (frameTime >= FRAME_RATE) {
			update();
			startTime = SDL_GetTicks();
		}		
		render();
	}
	//pedimos el nombre del jugador
    string name;
	cin >> name;
	//lee el archivo
	score.Load("score.txt");
	//añade la puntuacion de la partida y ordena las mejores
	score.addScore(name, points);
	//guarda el archivo
	score.save("score.txt");
	
}
//metodo que actualiza el estado del juego
void Game::update() {
	
	generateBalloons();
	

	for (auto it = objects.begin(); it != objects.end(); it++) {

		(*it)->update();

	}
	//actualizamos arco y generamos globos
	//bow->update();
	//it = objects.begin();
	//while (it != objects.end()); ; ++it;
	for (auto it = objectsToErase.begin(); it != objectsToErase.end(); ++it) {

		objects.remove(*it);
	}
	objectsToErase.clear();
		
	//actualizacion de globos
	/*for (int i = 0; i < balloons.size(); i++) {
		//si el update devuelve true destruimos ese globo y lo quitamos del vector
		arrows[i]->update();

	}*/
	//actualizacion de flechas
	/*for (int j = 0; j < arrows.size(); j++) {
		//si el update devuelve true destruimos esa flecha y la quitamos del vector
		arrows[j]->update();
			
	}*/
}
//metodo que renderiza todos los objetos del juego
void Game::render() const {
	//
	//limpiamos
	SDL_RenderClear(renderer);
	//renderizado del fondo
	SDL_Rect bk;
	bk = { 0,0,WIN_WIDTH,WIN_HEIGHT };
	
	textures[level]->render(bk, SDL_FLIP_NONE);
	//renderizado arco
	for (auto it = objects.begin(); it != objects.end(); ++it){
	
		(*it)->render();

	}

	
	scoreboard->render();
	SDL_RenderPresent(renderer);
}
//metodo que controla los eventos del juego
void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		else {
			
			dynamic_cast<Bow*>(*objects.begin())->handleEvent(event);
				
		}
	}
}
//metodo que genera globo cada 2 segundos
void Game::generateBalloons() {
	
	const int FRAME_RATEGLOB = 2000; // cada dos segundos generamos un globo
	frameBaloonTime = SDL_GetTicks() - startBaloonTime;
	if (frameBaloonTime >= FRAME_RATEGLOB) {
		int h =  rand() % 320 + 400;
		int color = rand() % 7;
		double velocidad = rand() % 5 + 0.5;
		Balloon* globo=new  Balloon(Point2D{ (double)h,600 }, 80, 80, Vector2D(0, -velocidad), textures[2], false, 0, this, color);
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
	if (flechas!=0)
	{
		timeshoot = SDL_GetTicks();
		timecharge =(timeshoot- timecharge)/1000;
		if (timecharge>10)
		{
			timecharge = 10;
		}
		Arrow* flecha = new Arrow(Vector2D(timecharge + 2, 0), textures[4], this, Point2D(pos.getX() + 20, pos.getY() + 30), 90, 20);
		auto it = objects.insert(objects.end(), flecha);
		arrows.push_back(flecha);
		flecha->setItList(it);
		flechas--;

		scoreboard->Arrows();
	}
	
}
//metodo para añadir puntos
void Game::AddPoints()
{
	points += POINT_ADD;
	scoreboard->Puntuacion(points);
}


//metodo que mira si alguna flecha ha tocado con un globo
bool Game::OnCollisionEnter(SDL_Rect* rectBalloon) {
	
	
		for (auto it= arrows.begin();it!=arrows.end();++it)
		{
			if (SDL_HasIntersection(rectBalloon, (*it)->getCollisionRect()))
			{
				return true;
			}
		}
	
	return false;
}

void Game::KillObject(list<GameObject*>::iterator it) {

	objectsToErase.push_back(*it);
}

void Game::CreateButterflys() {
	int posiX, posiY, velX, velY;
	for (uint j = 0; j < NUM_BUTTERFLYS; j++) {
		posiX = rand() %  600+ 100;
		posiY = rand() % 400 + 100;
		velX = rand() % 5 - 2;
		velY = rand() % 5 - 2;

		Butterfly* mariposa = new Butterfly(Point2D((double)posiX, (double)posiY), Vector2D((double)velX, (double)velY), 60, 60, textures[7], this);
		auto it = objects.insert(objects.end(), mariposa);
		mariposa->setItList(it);
	}
}
/*
void Game::NewLvl()
{ 
	level++;
	for (int i = 0; i < arrows.size(); i++) {
		delete arrows[i];
		arrows[i] = nullptr;
	}
	for (int j = 0; j < balloons.size(); j++) {
		delete balloons[j];
		balloons[j] = nullptr;
	}
}*/
