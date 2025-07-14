#pragma once

#include "Board.h"

class BoardHistory
{
    public:
        void AddBoard(Board board);
        bool IsThreeFoldRepetition();
        bool ClearHistory();
    private:
        std::vector<Board> m_boardHistory;
};