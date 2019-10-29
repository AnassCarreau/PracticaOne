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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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
	bow = new Bow(Point2D(0, 0), 80, 80, Vector2D(0, 10), textures[1],textures[3], false, this, nullptr);
	scoreboard = new Scoreboard(Point2D(300,0),40,45,textures[6],textures[5],10,0);
	flechas = 10;
	
	run();
}
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

}void Game::run() {
	uint32_t startTime, frameTime; //variables para el control del tiempo
	startTime = SDL_GetTicks(); //tiempo inicial en milisegundos
	const int FRAME_RATE = 2000 ; //cada 2 segundos genero un globo
	const int FRAME_RATE_GLOBAL = 60;
	while (!exit) { 
		handleEvents();
		
		frameTime = SDL_GetTicks() - startTime;
		if (frameTime >= FRAME_RATE) {
			generateBalloons(); //genera globo
			startTime = SDL_GetTicks();
		}
		
		
		update();
		render();
	}
	this->~Game();
}
void Game::update() {
	bow->update();
	for (int i = 0; i < balloons.size(); i++) {
		if (balloons[i]->update()) {
			delete balloons[i];
			balloons.erase(balloons.begin()+i);
			scoreboard->Puntuacion(10);
		}
	}
	for (int j = 0; j < arrows.size(); j++) {
		if (arrows[j]->update()) {
			delete arrows[j];
			arrows.erase(arrows.begin() + j);
		}
	}
}

void Game::render() const {

	SDL_RenderClear(renderer);
	SDL_Rect bk;
	bk = { 0,0,WIN_WIDTH,WIN_HEIGHT };
	
	textures[0]->render(bk, SDL_FLIP_NONE);
	bow->render();
	for (int j = 0; j < arrows.size(); j++)
	{
		arrows[j]->render();
	}
	for (int i = 0; i < balloons.size(); i++)
	{
		balloons[i]->render();
	}	

	scoreboard->render();

	SDL_RenderPresent(renderer);
}
void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		else {
			bow->handleEvents(event ); 
		}
	}
}

void Game::generateBalloons() {
	int h = rand() % 320+350;
	int color = rand() % 7;
	Balloon* globo = new Balloon(Point2D{(double)h,600 }, 80, 80, Vector2D(0, 0.05), textures[2], false, 0, this, color);
	balloons.push_back(globo);
}
void Game::CargaFlecha()
{
	timecharge = SDL_GetTicks();
}
void Game::DisparaFlecha(Point2D pos) {
	if (flechas!=0)
	{
		timeshoot = SDL_GetTicks();
		timecharge =(timeshoot- timecharge)/10000;
		Arrow* flecha = new Arrow(Point2D(pos.getX() + 20, pos.getY() + 30), 90, 20, Vector2D(timecharge,0), textures[4]);
		arrows.push_back(flecha);
		scoreboard->Arrows();
		flechas--;
	}
	
}



bool Game::MiraChoques(SDL_Rect* rectBalloon) {
	
		for (int i = 0; i < arrows.size(); i++)
		{
			if (SDL_HasIntersection(rectBalloon, arrows[i]->PosFlecha()))
			{
				return true;
			}
		}
	
	return false;
	
}

	

