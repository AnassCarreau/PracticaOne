#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

#include <SDL.h>
class EventHandler
{
	public:
		virtual void handleEvent(SDL_Event& event)=0;
};
#endif

