#ifndef LEGALITYCHECKER_H
#define LEGALITYCHECKER_H

#include "Board.h"
#include "Move.cpp"

class LegalityChecker
{
    public:
        LegalityChecker(const Board& board);
        bool CheckMoveLegality(Move move) const;
    private:
        Board m_board;
};

#endif