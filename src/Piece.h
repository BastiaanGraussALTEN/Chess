#ifndef PIECE_H
#define PIECE_H

#include "Color.cpp"
#include "Coord.cpp"

class Piece
{
    public:
        Piece(Color color, Coord positionOfPiece);
        virtual ~Piece();
        Color color;
        Coord position;
};

#endif