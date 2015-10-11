
#ifndef _MOVEMENTHANDLER_H_
#define _MOVEMENTHANDLER_H_

#include <list>
#include "Movable.h"

class MovementHandler
{
public:
    void put(Movable *);
    void tick();
    void takeout(Movable *);

    void printMovableCount();

private:
    std::list<Movable *> movables;
};

#endif // _MOVEMENTHANDLER_H_
