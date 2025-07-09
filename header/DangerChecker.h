#pragma once

#include "LegalityChecker.h"

class DangerChecker
{
    public:
        DangerChecker(const Board& board, const Color& color);
        bool IsKingUnderAttack() const;
        bool IsSquareUnderAttack(Square targetSquare) const;
    private:
        Square GetKingPosition() const;
        Board m_board;
        LegalityChecker m_legalityChecker;
        Color m_color;
};