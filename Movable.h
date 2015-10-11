
#ifndef _MOVABLE_H_
#define _MOVABLE_H_

#include <string>

using std::string;

class Movable
{
public:
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    int x = 0, y = 0;
    int pixelSpeed = 2;
    bool moving = false;
    Direction direction = UP;

    Movable();
    ~Movable();

    bool isMoving();
    void move();
    string getCoordString();
};

#endif // _MOVABLE_H_
