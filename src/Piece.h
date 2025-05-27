#ifndef PIECE_H
#define PIECE_H

#include "Coord.cpp"

class Piece
{
    public:
    Piece(bool isPieceWhite, Coord positionOfPiece);
    bool isWhite;
    Coord position;
};

#endif