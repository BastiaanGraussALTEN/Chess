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
        static std::shared_ptr<Piece> CreatePawn(Color color, Coord position);
        static std::shared_ptr<Piece> CreateBishop(Color color, Coord position);
        static std::shared_ptr<Piece> CreateKnight(Color color, Coord position);
        static std::shared_ptr<Piece> CreateRook(Color color, Coord position);
        static std::shared_ptr<Piece> CreateQueen(Color color, Coord position);
        static std::shared_ptr<Piece> CreateKing(Color color, Coord position);
};

#endif