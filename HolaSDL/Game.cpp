#include "Game.h"
#include "checkML.h"
#include <string>
#include <iostream>
#include <random>
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

	bow = new Bow(Point2D(0, 0), 80, 80, Vector2D(0, 10), textures[1], false);
	globo = new Balloon(Point2D{ 600,520}, 80, 80, Vector2D(0, 0.01), textures[2], false, 0, nullptr);
	globos[0]= new Balloon(Point2D{ 500,580 }, 80, 80, Vector2D(0, 0.01), textures[2], false, 0, nullptr);
	run();
}
Game::~Game() {
	for (uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}void Game::run() {
	while (!exit) { // Falta el control de tiempo
		handleEvents();
		update();
		render();
	}
}
void Game::update() {
	bow->update();
	globo->update();
	globos[0]->update();

	
}

void Game::render() const {

	SDL_RenderClear(renderer);
	SDL_Rect bk;
	bk = { 0,0,WIN_WIDTH,WIN_HEIGHT };
	
	textures[0]->render(bk, SDL_FLIP_NONE);
	bow->render();
	globo->render();
	globos[0]->render();

		
		SDL_RenderPresent(renderer);
}
void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		else { bow->handleEvents(event); }
		
	}
}