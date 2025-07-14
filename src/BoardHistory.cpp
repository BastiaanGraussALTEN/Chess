#include "../header/BoardHistory.h"

#include <map>
#include <iostream>

bool BoardHistory::IsThreeFoldRepetition()
{
    if (m_boardHistory.size() < 3)
    {
        return false;
    }

    for (int i = 0; i < m_boardHistory.size(); i++)
    {
        Board boardToCompare = m_boardHistory[i];
        int count = 1;
        for (int j = 0; j < m_boardHistory.size(); j++)
        {
            if (i != j && boardToCompare == m_boardHistory[j])
            {
                count += 1;
                if (count == 3)
                {
                    return true;
                }
            }
        } 
    }

    return false;
}

void BoardHistory::AddBoard(Board board)
{
    m_boardHistory.push_back(board);
}