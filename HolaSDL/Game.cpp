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

	gameStateMachine = new GameStateMachine(this);
	gameStateMachine->changeState(new MainMenuState(this));
	
	run();	
}
//metodo de destruccion de basura
Game::~Game() {

	for (uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
//metodo principal del juego con estructura->eventos->actualizar->renderizar
void Game::run() {
	
	uint32_t startTime, frameTime; //variables para el control del tiempo
	startTime = SDL_GetTicks(); //tiempo inicial en milisegundos
	
	const int FRAME_RATE = 20 ; //20fps
	while (!exit /*&& NUM_BUTTERFLYS!=0 && level<6 && NUM_FLECHAS!=0*/) { 
		handleEvents();
		//actualizamos el juego cada Frame_Rate
		frameTime = SDL_GetTicks() - startTime;
		if (frameTime >= FRAME_RATE) {
			update();
			startTime = SDL_GetTicks();
		}		
		render();
	}
	/*int g;
	ofstream output;
	cout << "Si quieres guardar la partida pulsa '2'" << endl;
	cin >> g;
	if (g == 2) saveToFile(output);*/
}
//metodo que actualiza el estado del juego
void Game::update() {
	gameStateMachine->update();
}
//metodo que renderiza todos los objetos del juego
void Game::render() const {
	//limpiamos
	SDL_RenderClear(renderer);
	gameStateMachine->render();
	SDL_RenderPresent(renderer);
}
//metodo que controla los eventos del juego
void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		else {
			/*GameStateMachine* gm = new GameStateMachine(this);
			gm->currentState()->handleEvents(event);*/
			gameStateMachine->handleEvents(event);
		}
	}
}
void Game::Play() {
	gameStateMachine->changeState(new PlayState(this));
}
void Game::Pause() {
	gameStateMachine->changeState(new PauseState(this));
}
void Game::Exit() {
	SDL_Quit();
}
void Game::Load() {
	
}

void Game::Save() {

}

void Game::Menu() {
	gameStateMachine->changeState(new MainMenuState(this));
}
Texture* Game::GetTexture(int index) {
	return textures[index];
}

SDL_Renderer* Game::GetRenderer() {
	return renderer;
}