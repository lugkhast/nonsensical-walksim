
#include <iostream>

#include "MovementHandler.h"

void MovementHandler::put(Movable *movable)
{
    this->movables.push_back(movable);
}

void MovementHandler::takeout(Movable *movable)
{
    this->movables.remove(movable);
}

void MovementHandler::tick()
{
    std::list<Movable *>::iterator it;
    std::list<Movable *> *movables = &(this->movables);
    Movable *movable;

    for (it = movables->begin(); it != movables->end(); ++it) {
        movable = *it;
        movable->move();
    }
}

std::list<Movable *> MovementHandler::getMovables()
{
    return this->movables;
}

void MovementHandler::printMovableCount()
{
    std::cout << "We have "
        << this->movables.size()
        << " movables!" << std::endl;
}
