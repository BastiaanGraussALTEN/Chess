#include "../header/BoardHistory.h"

#include <unordered_map>

bool BoardHistory::IsThreeFoldRepetition()
{
    if (m_boardHistory.size() > 2)
    {
        // std::unordered_map<Board, int> countBoards;
        
    }
    return false;
}

void BoardHistory::AddBoard(Board board)
{
    m_boardHistory.push_back(board);
}