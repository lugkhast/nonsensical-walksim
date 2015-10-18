
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
    delete this->window;
    this->window = NULL;

    SDL_Quit();
}

void SDLApp::render()
{
    SDL_Rect fillRect;
    MovementHandler movementHandler = this->world->getMovementHandler();
    auto movables = movementHandler.getMovables();
    Movable *movable;

    fillRect.w = 16;
    fillRect.h = 16;

    SDL_FillRect(
        this->windowSurface,
        NULL,
        SDL_MapRGB(this->windowSurface->format, 0x00, 0x00, 0x00)
    );

    for (auto it = movables.begin(); it != movables.end(); ++it) {
        movable = *it;
        fillRect.x = movable->x;
        fillRect.y = movable->y;

        SDL_FillRect(
            this->windowSurface,
            &fillRect,
            SDL_MapRGB(
                this->windowSurface->format,
                0xFF, 0xFF, 0xFF
            )
        );
    }

    this->window->updateSurface();
}

void SDLApp::start()
{
    this->quit = false;
    SDL_Event e;

    this->window = new lsWindow("Walking Simulator 2016");
    this->windowSurface = this->window->getSDLSurface();

    while(!this->quit) {
        while ( SDL_PollEvent( &e ) != 0 ) {
            this->quit = this->evtHandler->handleEvent(&e);
        }

        this->world->tick();

        this->render();
    }
}

SDLApp::SDLApp()
{
    this->initSDL();

    this->player = new Movable;
    this->world = new World;
    this->world->putMovable(this->player);

    this->evtHandler = new SDLEventHandler(this->player, this->world);
}

SDLApp::~SDLApp()
{
    this->cleanupSDL();

    delete this->evtHandler;
    delete this->world;
    delete this->player;
}
