#include "Game.h"
#include <string>
using namespace std;
/*enum TextureNames ("..\\images\\bg1.png", };
enum { background= "..\\images\\bg1.png", bow, arrow };*/
const char* types[] = { "..\\images\\bg1.png", "..\\images\\bow2.png", "..\\images\\arrow1.png" };

Game::Game() {
	// We first initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Hola Jaime2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw "Error loading the SDL window or renderer";
	// We now create the textures
	for (uint i = 0; i < NUM_TEXTURES; i++) {
		
		textures[i]->load(types[i], 1, 1);
	}
	// We finally create the game objects
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