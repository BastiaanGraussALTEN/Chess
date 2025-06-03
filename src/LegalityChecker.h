#ifndef LEGALITYCHECKER_H
#define LEGALITYCHECKER_H

#include "Board.h"

class LegalityChecker
{
    public:
        LegalityChecker(Board board);
    private:
        Board m_board;
};

#endif