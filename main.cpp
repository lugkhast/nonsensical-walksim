#include <iostream>

#include "MovementHandler.h"
#include "Movable.h"
#include "SDLApp.h"

int main(int argc, char **argv)
{
    std::cout << "Hello, world!" << std::endl;

    Movable *m1, *m2;
    m1 = new Movable();
    m2 = new Movable();

    MovementHandler mh;
    mh.put(m1);
    mh.put(m2);

    mh.printMovableCount();
    mh.tick();

    std::cout << m1->getCoordString() << std::endl;

    SDLApp app;
    app.start();

    return 0;
}
