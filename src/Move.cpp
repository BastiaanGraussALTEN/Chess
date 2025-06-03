#ifndef MOVE
#define MOVE

#include "Square.cpp"

struct Move
{
    Move(Square startCoord, Square endCoord) :  Start(startCoord), End(endCoord){};
    Square Start;
    Square End;
};

#endif