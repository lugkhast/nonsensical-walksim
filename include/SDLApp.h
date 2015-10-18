
#ifndef _SDLAPP_H_
#define _SDLAPP_H_

#include <SDL2/SDL.h>

#include "MovementHandler.h"
#include "Movable.h"
#include "SDLEventHandler.h"
#include "World.h"

#include "lugSDL/lsWindow.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class SDLApp
{
public:
    SDLApp();
    ~SDLApp();
    void start();

    void handleEvent(SDL_Event *event);
    void render();

private:
    bool initSDL();
    void cleanupSDL();

    World *world;
    Movable *player;
    SDLEventHandler *evtHandler;

    SDL_Surface *windowSurface = NULL;
    lsWindow *window = NULL;
    bool quit;
};

#endif // _SDLAPP_H_
