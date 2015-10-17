
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

    return shouldQuit;
}
