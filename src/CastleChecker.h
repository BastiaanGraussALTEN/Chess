#ifndef CASTLECHECKER_H
#define CASTLECHECKER_H

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
};

#endif