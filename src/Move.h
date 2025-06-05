#ifndef MOVE_H
#define MOVE_H

#include "Square.h"

struct Move
{
    Move(Square startCoord, Square endCoord) :  start(startCoord), end(endCoord){};
    Square start;
    Square end;
};

#endif