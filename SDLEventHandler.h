
#ifndef _SDLEVENTHANDLER_H_
#define _SDLEVENTHANDLER_H_

#include <SDL2/SDL.h>

#include "Movable.h"
#include "World.h"

class SDLEventHandler
{
public:
    SDLEventHandler(Movable *player, World *world);
    bool handleEvent(SDL_Event *event);

    void onKeyDown(SDL_Event *event);
    void onKeyUp(SDL_Event *event);

private:
    Movable *player;
    World *world;
};

#endif // _SDLEVENTHANDLER_H_
