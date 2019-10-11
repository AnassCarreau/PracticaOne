
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <vector>


using namespace std;
using Textures = vector<SDL_Texture>;
using uint = unsigned int;

void firstTest() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	const uint winWidth = 800;
	const uint winHeight = 600;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("First test with SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)
		cout << "Error cargando SDL" << endl;
	else {
		//direcciones de las imagenes que vamos a abrir
		string filename = "..\\images\\background1.png";
		string filename2 = "..\\images\\dog.png";
		string filename3 = "..\\images\\helicopter.png";
		//crecion de las texturas con dichas imagenes
		SDL_Surface* fondo = IMG_Load(filename.c_str());
		SDL_Surface* perraco = IMG_Load(filename2.c_str());
		SDL_Surface* helicopterito = IMG_Load(filename3.c_str());
		SDL_Texture* textureFondo;
		SDL_Texture* texturePerraco;
		SDL_Texture* textureHelicoptero;
		
		textureFondo = SDL_CreateTextureFromSurface(renderer, fondo);
		texturePerraco = SDL_CreateTextureFromSurface(renderer, perraco);
		textureHelicoptero = SDL_CreateTextureFromSurface(renderer, helicopterito);
		//liberamos las variables auxiliares surface
		SDL_FreeSurface(fondo);
		SDL_FreeSurface(perraco);
		SDL_FreeSurface(helicopterito);
		
		//Para saber el tamaño de la textura del perro
		int textW, textH;
		SDL_QueryTexture(texturePerraco, nullptr, nullptr, &textW, &textH);
		int textFrameW = textW / 6;
		int textFrameH = textH / 1;
		//Para saber el tamaño de la textura del helicoptero
		int textW2, textH2;
		SDL_QueryTexture(textureHelicoptero, nullptr, nullptr, &textW2, &textH2);
		int textFrameW2 = textW2 / 5;
		int textFrameH2 = textH2 / 1;
		//Declaramos las variables rect para el rectangulo fuente y el rectangulo destino del perro y del helicoptero
		SDL_Rect srcRect, destRect, srcRect2, destRect2;
		srcRect.w = textW / 6; srcRect.h = textH;
		srcRect.x = srcRect.y = 0;
		destRect.w = textFrameW;
		destRect.h = textFrameH;
		destRect.x = 0;
		destRect.y = 452;

		srcRect2.w = textW2 / 5; srcRect2.h = textH2;
		srcRect2.x = srcRect2.y = 0;
		destRect2.w = textFrameW2;
		destRect2.h = textFrameH2;
		destRect2.x = 600;
		destRect2.y = 180;
		
		bool exit = false;
		int i = 0;
		int j = 799;
		SDL_Event event;

		uint32_t startTime, frameTime;
		//constante que define los milisegundos a partir de los que se actualiza el juego
		const int FRAME_RATE = 10;
		//constante que define el tiempo de cambio de un frame al siguiente del perro y el helicoptero
		const int TIME_PER_FRAME = 100;

		//bucle de juego
		while (!exit) {

			startTime = SDL_GetTicks();

			
			destRect2.x = j;

			//este segundo bucle nos permite cerrar la ventana SDL sin necesidad de esperar el SDL_Delay
			while (SDL_PollEvent(&event) && !exit) {
				if (event.type == SDL_QUIT)
					exit = true;
				else if (event.type == SDL_KEYDOWN) {
					if (event.key.keysym.sym == SDLK_h) {
						srcRect2.x = textFrameW2 * int(((SDL_GetTicks() / TIME_PER_FRAME) % 5));
						j = j % 800;
						if (j >= 0) {
							j--;
						}
						else j = 799;
					}

					else if (event.key.keysym.sym == SDLK_d) {
						srcRect.x = textFrameW * int(((SDL_GetTicks() / TIME_PER_FRAME) % 6));
						i = i % 800;
						destRect.x = i;
						i++;
					}

					else if (event.key.keysym.sym == SDLK_j) {

					}

					else if (event.key.keysym.sym == SDLK_g) {

					}
				}	

			}
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

			//limpia pantalla
			SDL_RenderClear(renderer);

			//copia en buffer
			SDL_RenderCopy(renderer, textureFondo, nullptr, nullptr);
			SDL_RenderCopy(renderer, texturePerraco, &srcRect, &destRect);
			SDL_RenderCopy(renderer, textureHelicoptero, &srcRect2, &destRect2);
			
			//muestra la escena
			SDL_RenderPresent(renderer);

			frameTime = SDL_GetTicks() - startTime;
			if (frameTime < FRAME_RATE)
				SDL_Delay(FRAME_RATE - frameTime); // Suspende por el tiempo restante
		}		
	}
	//finalizacion
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char* argv[]){
	firstTest();
	return 0;
}