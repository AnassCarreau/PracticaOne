#ifndef SDLERROR_H_
#define SDLERROR_H_

#include "ArrowsError.h";
#include "Game.h";
#include <string>

class SDLError:public ArrowsError
{
	public:
		SDLError() : ArrowsError(SDL_GetError()) {};
};
#endif

