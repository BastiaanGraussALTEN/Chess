#pragma once

#include "Square.h"
#include "PieceType.h"

struct Move
{
    Move(Square startCoord, Square endCoord) :  start(startCoord), end(endCoord){};
    bool operator==(const Move& rhs) const
    {
        return this->start == rhs.start && this->end == rhs.end;
    }
    Square start;
    Square end;
    PieceType piece;
    bool isPromotion = false;
    PieceType promotionPiece = PieceType::Queen;
    bool isCastleKingside = false;
    bool isCastleQueenside = false;
    bool isLegal = false;
};