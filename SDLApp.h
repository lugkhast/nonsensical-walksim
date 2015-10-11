
#ifndef _SDLAPP_H_
#define _SDLAPP_H_

#include <SDL2/SDL.h>


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class SDLApp
{
public:
    SDLApp();
    ~SDLApp();
    void start();

private:
    bool initSDL();
    void cleanupSDL();
    SDL_Window *createWindow();

    SDL_Surface *windowSurface = NULL;
    SDL_Window *window = NULL;
};

#endif // _SDLAPP_H_
