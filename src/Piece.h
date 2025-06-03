#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "Color.cpp"
#include "Coord.cpp"

class Piece
{
    public:
        Piece(Color color, Coord positionOfPiece);
        virtual ~Piece();
        virtual std::vector<Coord> GetPossibleMoves() const = 0;
        Color color;
        Coord position;
};

#endif