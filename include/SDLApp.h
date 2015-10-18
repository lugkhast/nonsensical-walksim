#ifndef _SDLAPP_H_
#define _SDLAPP_H_

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "MovementHandler.h"
#include "Movable.h"
#include "SDLEventHandler.h"
#include "World.h"

#include "lugSDL/lsWindow.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

using std::string;

class SDLApp
{
public:
    SDLApp();
    ~SDLApp();
    void start();
    void render();

private:
    bool initSDL();
    void cleanupSDL();
    void handleWindowEvent(SDL_Event *event);
    SDL_Texture *loadTexture(string path);

    World *world;
    Movable *player;
    SDLEventHandler *evtHandler;

    SDL_Surface *windowSurface = NULL;
    SDL_Renderer *mRenderer = NULL;
    lsWindow *window = NULL;
    SDL_Texture *playerTexture = NULL;
    bool quit;
};

#endif // _SDLAPP_H_
