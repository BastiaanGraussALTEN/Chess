#pragma once

#include "Board.h"

class BoardHistory
{
    public:
        void AddBoard(Board board);
        bool IsThreeFoldRepetition();
    private:
        std::vector<Board> m_boardHistory;
};