#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H

#include <memory>
#include "Piece.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

class PieceFactory
{
    public:
        static std::shared_ptr<Piece> CreatePawn(bool isWhite, Coord position);
        static std::shared_ptr<Piece> CreateBishop(bool isWhite, Coord position);
        static std::shared_ptr<Piece> CreateKnight(bool isWhite, Coord position);
        static std::shared_ptr<Piece> CreateRook(bool isWhite, Coord position);
        static std::shared_ptr<Piece> CreateQueen(bool isWhite, Coord position);
        static std::shared_ptr<Piece> CreateKing(bool isWhite, Coord position);
};

#endif