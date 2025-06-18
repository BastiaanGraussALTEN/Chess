#include "MoveDialog.h"
#include <numeric>

MoveDialog::MoveDialog()
{
    m_moveNumber = 0;
}

void MoveDialog::SetMove(std::string move)
{
    m_moveNumber += 1;
    m_moveHistory.push_back(move);
}

void MoveDialog::ShowDialog()
{
    std::string moveHistory = GetMoveHistory();
    std::string dialog = GetSingleLineDialog();
    std::cout << moveHistory << dialog;
}

void MoveDialog::ShowErrorText()
{
    std::cout << "No valid move is given! Please try again\n";
}

Color MoveDialog::GetCurrentTurn()
{
    if (m_moveNumber % 2 == 0)
    {
        return Color::White;
    }
    else
    {
        return Color::Black;
    }
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
    if(m_moveNumber == 0)
    {
        return "";
    }

    std::string moveHistoryString = "\nMove history:";
    for(int i = 0; i < m_moveHistory.size(); i++)
    {
        // White to move
        if(i % 2 == 0)
        {
            moveHistoryString += "\n";
            int whiteMoveNumber = i / 2 + 1;
            moveHistoryString += std::to_string(whiteMoveNumber) + ".";
        }
        
        moveHistoryString += " " + m_moveHistory[i];
    }
    
    moveHistoryString += "\n\n";
    return moveHistoryString;
}
