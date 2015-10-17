
#include "World.h"

MovementHandler World::getMovementHandler()
{
    return this->movementHandler;
}

void World::putMovable(Movable *movable)
{
    this->movementHandler.put(movable);
}

void World::tick()
{
    this->movementHandler.tick();
}
