#include <iostream>

#include "GameConfig.h"
#include "SDLApp.h"
#include "lugSDL/lsException.h"

int main(int argc, char **argv)
{
    std::cout << "walksim "
        << GAME_VERSION_MAJOR << "." << GAME_VERSION_MINOR
        << std::endl;

    SDLApp *app = NULL;

    try {
        app = new SDLApp;
        app->start();
    } catch (lsException ex) {
        std::cout << "Caught exception, exiting: " << std::endl
            << ex.message << std::endl;
    }

    return 0;
}
