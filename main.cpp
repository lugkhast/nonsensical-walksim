#include <iostream>

#include "GameConfig.h"

#include "MovementHandler.h"
#include "Movable.h"
#include "SDLApp.h"

int main(int argc, char **argv)
{
    std::cout << "walksim "
        << GAME_VERSION_MAJOR << "." << GAME_VERSION_MINOR
        << std::endl;

    SDLApp app;
    app.start();

    return 0;
}
