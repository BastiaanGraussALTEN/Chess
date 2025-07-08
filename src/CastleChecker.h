#pragma once

#include "DangerChecker.h"

class CastleChecker
{
    public:
        CastleChecker(const Board& board, const LegalityChecker& legalityChecker, const DangerChecker& dangerChecker, const Color& color);
        bool CanCastleKingSide() const;
        bool CanCastleQueenSide() const;
    private:
        Color m_color;
        Board m_board;
        LegalityChecker m_legalityChecker;
        DangerChecker m_dangerChecker;
        bool KingAndRookAreOnCorrectSquare(Square kingSquare, Square rookSquare) const;
        bool KingOrRookHasMoved(Square kingSquare, Square rookSquare) const;
        bool IsAPieceBetweenKingAndRook(std::vector<Square> kingSquares) const;
        bool KingMovesOverAttackSquare(std::vector<Square> kingSquares) const;
};