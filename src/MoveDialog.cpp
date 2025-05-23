#include "MoveDialog.h"
#include <numeric>

MoveDialog::MoveDialog()
{
    m_moveNumber = 0;
}

void MoveDialog::SetMove(std::string move)
{
    m_moveNumber += 1;
    if(m_moveNumber % 2 == 0)
    {
        m_moveHistory.push_back(move);
    }
    if(m_moveNumber % 2 != 0 && m_moveNumber > 1)
    {
        m_moveHistory.push_back("\n" + move + "\t");
    }
    if(m_moveNumber % 2 != 0 && m_moveNumber == 1)
    {
        m_moveHistory.push_back(move + "\t");
    }
}

void MoveDialog::ShowDialog()
{
    std::string moveHistory = GetMoveHistory();
    std::string dialog = GetSingleLineDialog();
    std::cout << moveHistory << dialog;
}

std::string MoveDialog::GetSingleLineDialog()
{
    if (m_moveNumber % 2 == 0)
    {
        return "White to move, insert your Move: ";
    }
    else
    {
        return "Black to move, insert your Move: ";
    }
}

std::string MoveDialog::GetMoveHistory()
{
    std::string oneString = std::accumulate(m_moveHistory.begin(), m_moveHistory.end(), std::string(""));
    oneString = "\nMove history:\n" + oneString + "\n\n";
    return oneString;
}
