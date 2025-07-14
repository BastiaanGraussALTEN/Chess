#include "../header/BoardHistory.h"

#include <unordered_map>

bool BoardHistory::IsThreeFoldRepetition()
{
    if (m_boardHistory.size() < 3)
    {
        return false;
    }

    std::unordered_map<Board, int> countBoards;
    
    for (const auto& board : m_boardHistory) 
    {
        if (++countBoards[board] == 3)
        {
            return true;
        }
    }

    return false;
}

void BoardHistory::AddBoard(Board board)
{
    m_boardHistory.push_back(board);
}