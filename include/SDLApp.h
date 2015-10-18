
#ifndef _SDLAPP_H_
#define _SDLAPP_H_

#include <SDL2/SDL.h>

#include "MovementHandler.h"
#include "Movable.h"
#include "World.h"
#include "SDLEventHandler.h"

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
    SDL_Window *createWindow();

    World *world;
    Movable *player;
    SDLEventHandler *evtHandler;

    SDL_Surface *windowSurface = NULL;
    SDL_Window *window = NULL;
    bool quit;
};

#endif // _SDLAPP_H_
