#ifndef MOVE
#define MOVE

#include "Square.cpp"

struct Move
{
    Move(Square startCoord, Square endCoord) :  start(startCoord), end(endCoord){};
    Square start;
    Square end;
};

#endif