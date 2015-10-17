
#include <iostream>
#include <stdio.h> // needed for snprintf

#include "Movable.h"

Movable::Movable() {
};

Movable::~Movable() {
};

bool Movable::isMoving()
{
    return this->moving;
}

void Movable::move()
{
    switch (this->direction) {
    case UP:
        this->y -= this->pixelSpeed;
        break;
    case DOWN:
        this->y += this->pixelSpeed;
        break;
    case LEFT:
        this->x -= this->pixelSpeed;
        break;
    case RIGHT:
        this->x += this->pixelSpeed;
        break;
    }
}

string Movable::getCoordString()
{
    char buf[20];
    snprintf(buf, sizeof(buf), "(%d, %d)", this->x, this->y);
    string coordString = buf;

    return coordString;
}
