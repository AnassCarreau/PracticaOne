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

	//Cracion de las texturas
	for (uint i = 0; i < NUM_TEXTURES; i++) {
	
		textures[i] = new Texture(renderer, imags[i].filename, imags[i].nRows, imags[i].nCols);
		
	}
	//Creacion de los gameobjects (los globos y las flechas los generamos mediante un metodo que los genera en un vector)
	bow = new Bow(Point2D(0, 0), 80, 80, Vector2D(10, 10), textures[1], false, this, nullptr);
	run();
}
Game::~Game() {
	for (uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

}void Game::run() {
	uint32_t startTime, frameTime; //variables para el control del tiempo
	startTime = SDL_GetTicks(); //tiempo inicial en milisegundos
	const int FRAME_RATE = 2000; //cada 2 segundos genero un globo
	while (!exit) { 
		handleEvents();
		frameTime = SDL_GetTicks() - startTime; // Tiempo desde última actualización
		if (frameTime >= FRAME_RATE) {
			generateBalloons(); //genera globo
			startTime = SDL_GetTicks();
		}
		update(); //actualiza los objetos del juego
		render(); //renderiza los objetos del juego
	}
}
void Game::update() {
	bow->update();
	for (int i = 0; i < balloons.size(); i++) {
		if (balloons[i]->update()) {
			delete balloons[i];
			balloons.erase(balloons.begin()+i);
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
	SDL_RenderPresent(renderer);
}
void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		else {
			bow->handleEvents(event ); }
	}
}

void Game::generateBalloons() {
	int h = rand() % 320+400;
	int color = rand() % 9;
	Balloon* globo = new Balloon(Point2D{(double)h,600 }, 80, 80, Vector2D(0, 0.05), textures[2], false, 0, this, color);
	balloons.push_back(globo);
}
void Game::CargaFlecha(Point2D pos,Arrow* flecha)
{
	bow = new Bow(pos, 80, 80, Vector2D(0, 10), textures[3], true,this,flecha);
}
void Game::DisparaFlecha(Point2D pos) {
	Arrow* flecha = new Arrow(Point2D(pos.getX(), pos.getY() + 30), 90, 20, Vector2D(0.1, 0), textures[4]);
	bow = new Bow(pos, 60, 80, Vector2D(0, 10), textures[1], false,this,flecha);
	arrows.push_back(flecha);
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
	

