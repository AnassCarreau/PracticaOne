#include "Game.h"
#include <string>
#include <iostream>
using namespace std;
typedef unsigned int uint;
/*enum TextureNames ("..\\images\\bg1.png", };
enum { background= "..\\images\\bg1.png", bow, arrow };*/
//const char* types[] = { "..\\images\\bg1.png", "..\\images\\bow2.png", "..\\images\\arrow1.png" };

Game::Game() {
	// We first initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Hola Jaime2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw "Error loading the SDL window or renderer";

	//Cracion de las texturas
	for (uint i = 0; i < NUM_TEXTURES; i++) {
		textures[i]->load(imags[i].filename, imags[i].nRows, imags[i].nCols);
	}
	//Cracion de los gameobjects
	bow = new Bow();
}
Game::~Game() {
	for (uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}void Game::run() {
	while (!exit) { // Falta el control de tiempo
	//	handleEvents();
		update();
		render();
	}
}
void Game::update() {
	bow->update();
	
}
void Game::render() const {
	SDL_RenderClear(renderer);
	textures[0]->render(/*destRect*/, SDL_FLIP_NONE);
	bow->render();
	
		SDL_RenderPresent(renderer);
}
/*void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		bow->handleEvents(event);
		
	}
}*/