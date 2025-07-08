#pragma once

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
        static std::shared_ptr<Pawn> CreatePawn(Color color, Square position);
        static std::shared_ptr<Bishop> CreateBishop(Color color, Square position);
        static std::shared_ptr<Knight> CreateKnight(Color color, Square position);
        static std::shared_ptr<Rook> CreateRook(Color color, Square position);
        static std::shared_ptr<Queen> CreateQueen(Color color, Square position);
        static std::shared_ptr<King> CreateKing(Color color, Square position);
};