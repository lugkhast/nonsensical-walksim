
#include <iostream>

#include "SDLApp.h"


bool SDLApp::initSDL()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL! SDL error: "
            << SDL_GetError() << std::endl;
        success = false;
    }

    return success;
}

void SDLApp::cleanupSDL()
{
    SDL_DestroyWindow(this->window);
    this->window = NULL;

    SDL_Quit();
}

SDL_Window *SDLApp::createWindow()
{
    window = SDL_CreateWindow(
        "SDL Tutorial",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (window == NULL) {
        std::cerr << "Window could not be created! SDL error: "
            << SDL_GetError() << std::endl;
    }

    return window;
}

void SDLApp::start()
{
    bool quit = false;
    SDL_Event e;

    this->window = this->createWindow();
    this->windowSurface = SDL_GetWindowSurface(this->window);
    SDL_FillRect(
        this->windowSurface,
        NULL,
        SDL_MapRGB(this->windowSurface->format, 0xFF, 0xFF, 0xFF)
    );

    while(!quit) {
        while ( SDL_PollEvent( &e ) != 0 ) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_UpdateWindowSurface( window );
    }
}

SDLApp::SDLApp()
{
    this->initSDL();
}

SDLApp::~SDLApp()
{
    this->cleanupSDL();
}
