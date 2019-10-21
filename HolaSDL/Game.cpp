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
	//Creacion de los gameobjects
	bow = new Bow(Point2D(0, 0), 80, 80, Vector2D(10, 10), textures[1], false, this, nullptr);
	globo=new Balloon(Point2D(0, 0), 80, 80, Vector2D(10, 10), textures[2], false, 0,this, 0);

	flecha = new Arrow(Point2D(500, 500), 10, 10, Vector2D(0, 10), textures[4]);

    

	
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
	while (!exit) { // Falta el control de tiempo
		handleEvents();
		frameTime = SDL_GetTicks() - startTime; // Tiempo desde �ltima actualizaci�n
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
	flecha->update();
	for (int i = 0; i < balloons.size(); i++) {
		balloons[i]->update();
	}
}

void Game::render() const {

	SDL_RenderClear(renderer);
	SDL_Rect bk;
	bk = { 0,0,WIN_WIDTH,WIN_HEIGHT };
	
	textures[0]->render(bk, SDL_FLIP_NONE);
	bow->render();
	flecha->render();
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
	globo = new Balloon(Point2D{(double)h,520 }, 80, 80, Vector2D(0, 0.05), textures[2], false, 0, nullptr, color);
	balloons.push_back(globo);
	
	//cout << balloons.size();
	
	
}
void Game::CargaFlecha(Point2D pos,Arrow* flecha)
{
	bow = new Bow(pos, 80, 80, Vector2D(0, 10), textures[3], true,this,flecha);
}
void Game::DisparaFlecha(Point2D pos) {
	bow = new Bow(pos, 60, 80, Vector2D(0, 10), textures[1], false,this,flecha);
	
	flecha = new Arrow(Point2D(pos.getX(),pos.getY()+30), 90, 20, Vector2D(0.1,0), textures[4]);
}
/*bool Game::MiraChoques(Point2D &globa) {
	
	//Point2D glob = globo->Posglobo();
	Point2D flech = flecha->PosFlecha();
	Point2D diff = flech.operator-(globo->Posglobo());
	return diff.getX() < 5.00 && diff.getY() <10.00;

}*/
	

