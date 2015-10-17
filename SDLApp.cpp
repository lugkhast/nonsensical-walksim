
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

void SDLApp::handleEvent(SDL_Event *event)
{
    if (event->type == SDL_QUIT) {
        this->quit = true;
    } else if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
        case SDLK_UP:
            this->player->direction = Movable::UP;
            break;
        case SDLK_DOWN:
            this->player->direction = Movable::DOWN;
            break;
        case SDLK_LEFT:
            this->player->direction = Movable::LEFT;
            break;
        case SDLK_RIGHT:
            this->player->direction = Movable::RIGHT;
            break;
        }

        this->player->moving = true;
    } else if (event->type == SDL_KEYUP) {
        switch (event->key.keysym.sym) {
        case SDLK_UP:
            if (this->player->direction == Movable::UP) {
                this->player->moving = false;
            }
            break;
        case SDLK_DOWN:
            if (this->player->direction == Movable::DOWN) {
                this->player->moving = false;
            }
            break;
        case SDLK_LEFT:
            if (this->player->direction == Movable::LEFT) {
                this->player->moving = false;
            }
            break;
        case SDLK_RIGHT:
            if (this->player->direction == Movable::RIGHT) {
                this->player->moving = false;
            }
            break;
        }
    }
}

void SDLApp::render()
{
    SDL_Rect fillRect;
    auto movables = this->mh.getMovables();
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

    SDL_UpdateWindowSurface( this->window );
}

void SDLApp::start()
{
    this->quit = false;
    SDL_Event e;

    this->window = this->createWindow();
    this->windowSurface = SDL_GetWindowSurface(this->window);

    while(!this->quit) {
        while ( SDL_PollEvent( &e ) != 0 ) {
            this->handleEvent(&e);
        }

        this->mh.tick();

        this->render();
    }
}

SDLApp::SDLApp()
{
    this->initSDL();

    this->player = new Movable;
    this->mh.put(this->player);
}

SDLApp::~SDLApp()
{
    this->cleanupSDL();

    delete this->player;
}
