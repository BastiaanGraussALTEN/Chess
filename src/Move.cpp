#ifndef MOVE
#define MOVE

#include "Coord.cpp"

struct Move
{
    Move(Coord startCoord, Coord endCoord) :  Start(startCoord), End(endCoord){};
    Coord Start;
    Coord End;
};

#endif