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
	ArrowsGameObject* go[5];
	//go[0]= new Arrow();
   // go[1] = new Bow(Point2D(0, 0), 80, 80, Vector2D(0, 10), textures[1],textures[3], false, this, nullptr);
	flechas = 10;
	scoreboard = new Scoreboard(Point2D(300,0),25,35,textures[6],textures[5],flechas);
	
	run();
}
//metodo de destruccion de basura
Game::~Game() {
	for (uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];
	delete scoreboard;
	scoreboard = nullptr;
	delete bow;
	bow = nullptr;
	for (int i = 0; i < arrows.size(); i++) {
		delete arrows[i];
		arrows[i] = nullptr;
	}
	for (int j = 0; j < balloons.size(); j++) {
		delete balloons[j];
		balloons[j] = nullptr;
	}
	
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
	//actualizamos arco y generamos globos
	bow->update();
	generateBalloons();
	//actualizacion de globos
	for (int i = 0; i < balloons.size(); i++) {
		//si el update devuelve true destruimos ese globo y lo quitamos del vector
		arrows[i]->update();

	}
	//actualizacion de flechas
	for (int j = 0; j < arrows.size(); j++) {
		//si el update devuelve true destruimos esa flecha y la quitamos del vector
		arrows[j]->update();
			
	}
}
//metodo que renderiza todos los objetos del juego
void Game::render() const {


	//

	for (ArrowsGameObject*a:go)
	{
		a->render();
		a->update();
	}

	//
	//limpiamos
	SDL_RenderClear(renderer);
	//renderizado del fondo
	SDL_Rect bk;
	bk = { 0,0,WIN_WIDTH,WIN_HEIGHT };
	
	textures[level]->render(bk, SDL_FLIP_NONE);
	//renderizado arco
	bow->render();
	//renderizado flechas
	for (int j = 0; j < arrows.size(); j++)
	{
		arrows[j]->render();
	}
	//renderizado globos
	for (int i = 0; i < balloons.size(); i++)
	{
		balloons[i]->render();
	}	
	//renderizado scoreboard
	scoreboard->render();
	//lo presentamos todo en pantalla
	SDL_RenderPresent(renderer);
}
//metodo que controla los eventos del juego
void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		else {
			bow->handleEvents(event ); 
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
		double velocidad = rand() % 2 + 0.5;
		Balloon* globo = new Balloon(Point2D{ (double)h,600 }, 80, 80, Vector2D(0, velocidad), textures[2], false, 0, this, color);
		balloons.push_back(globo);
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
		arrows.push_back(flecha);
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
	
	
		for (int i = 0; i < arrows.size(); i++)
		{
			if (SDL_HasIntersection(rectBalloon, arrows[i]->PosFlecha()))
			{
				return true;
			}
		}
	
	return false;
	
}

void Game::KillObject(GameObject *object) {
	//object.erase().pushback(object);
	//delete object;
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
