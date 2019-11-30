#ifndef SDLERROR_H_
#define SDLERROR_H_

#include "ArrowsError.h";
#include "Game.h";

class SDLError:public ArrowsError
{
	public:
		static void SDL_DameError() { SDL_GetError(); };
		static void SDL_ErrorImagen() { IMG_GetError(); };
		
};
#endif

