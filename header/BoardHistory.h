#pragma once

#include "Board.h"

class BoardHistory
{
    public:
        void AddBoard(Board board);
        bool IsThreeFoldRepetition();
        void ClearHistory();
    private:
        std::vector<Board> m_boardHistory;
};