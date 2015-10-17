
#include "SDLEventHandler.h"

SDLEventHandler::SDLEventHandler(Movable *player, World *world)
{
    this->player = player;
    this->world = world;
}

bool SDLEventHandler::handleEvent(SDL_Event *event)
{
    bool shouldQuit = false;

    if (event->type == SDL_QUIT) {
        shouldQuit = true;
    } else if (event->type == SDL_KEYDOWN) {
        this->onKeyDown(event);
    } else if (event->type == SDL_KEYUP) {
        this->onKeyUp(event);
    }

    return shouldQuit;
}

void SDLEventHandler::onKeyDown(SDL_Event *event)
{
    this->player->moving = true;

    switch (event->key.keysym.sym) {
    case SDLK_w:
        this->player->direction = Movable::UP;
        break;
    case SDLK_s:
        this->player->direction = Movable::DOWN;
        break;
    case SDLK_a:
        this->player->direction = Movable::LEFT;
        break;
    case SDLK_d:
        this->player->direction = Movable::RIGHT;
        break;
    default:
        this->player->moving = false;
    }
}

void SDLEventHandler::onKeyUp(SDL_Event *event)
{
    switch (event->key.keysym.sym) {
    case SDLK_w:
        if (this->player->direction == Movable::UP) {
            this->player->moving = false;
        }
        break;
    case SDLK_s:
        if (this->player->direction == Movable::DOWN) {
            this->player->moving = false;
        }
        break;
    case SDLK_a:
        if (this->player->direction == Movable::LEFT) {
            this->player->moving = false;
        }
        break;
    case SDLK_d:
        if (this->player->direction == Movable::RIGHT) {
            this->player->moving = false;
        }
        break;
    }
}
