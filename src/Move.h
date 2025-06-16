#ifndef MOVE_H
#define MOVE_H

#include "Square.h"

struct Move
{
    Move(Square startCoord, Square endCoord) :  start(startCoord), end(endCoord){};
    bool operator==(const Move& rhs) const
    {
        return this->start == rhs.start && this->end == rhs.end;
    }
    Square start;
    Square end;
};

#endif