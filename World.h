
#ifndef _WORLD_H_
#define _WORLD_H_

#include "Movable.h"
#include "MovementHandler.h"

class World
{
public:
    MovementHandler getMovementHandler();
    void putMovable(Movable *movable);
    void tick();

private:
    MovementHandler movementHandler;
};

#endif // _WORLD_H_
