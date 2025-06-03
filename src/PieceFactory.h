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
        static std::shared_ptr<Piece> CreatePawn(Color color, Square position);
        static std::shared_ptr<Piece> CreateBishop(Color color, Square position);
        static std::shared_ptr<Piece> CreateKnight(Color color, Square position);
        static std::shared_ptr<Piece> CreateRook(Color color, Square position);
        static std::shared_ptr<Piece> CreateQueen(Color color, Square position);
        static std::shared_ptr<Piece> CreateKing(Color color, Square position);
};

#endif