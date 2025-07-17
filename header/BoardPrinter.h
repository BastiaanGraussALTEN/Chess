#pragma once

#include "Board.h"

class BoardPrinter
{
    public:
        BoardPrinter(const Board& board);
        void PrintEmptyBoard() const;
        void PrintBoard() const;
    private:
        Board m_board;
};