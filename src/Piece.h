#ifndef PIECE_H
#define PIECE_H

#include "Coord.cpp"

class Piece
{
    public:
        Piece(bool isPieceWhite, Coord positionOfPiece);
        virtual ~Piece();
        bool isWhite;
        Coord position;
};

#endif