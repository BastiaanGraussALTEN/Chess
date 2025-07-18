#include "../header/MoveDialog.h"
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
    std::cout << GetSingleLineDialog() << std::endl;
}

void MoveDialog::ShowMoveHistory()
{
    std::cout << GetMoveHistory() << std::endl;
}

void MoveDialog::ShowStringNotValid()
{
    std::cout << "The move string is not valid! Please try again\n" << std::endl;
}

void MoveDialog::ShowMoveNotLegal()
{
    std::cout << "The move you are trying to play is not legal! Please try again\n" << std::endl;
}

void MoveDialog::ShowPieceWrongColor()
{
    std::cout << "You are trying to move a piece of the wrong color! Please try again\n" << std::endl;
}

void MoveDialog::ShowCheckMate()
{
    std::cout << "Checkmate!\n" << std::endl;
}

void MoveDialog::ShowStaleMate()
{
    std::cout << "Stalemate!\n" << std::endl;
}

void MoveDialog::Show50MoveDraw()
{
    std::cout << "Draw caused by fifty-move rule!\n" << std::endl;
}

void MoveDialog::ShowThreeFoldRepetition()
{
    std::cout << "Draw caused by three-fold repetition!\n" << std::endl;
}

void MoveDialog::ShowInsufficientMaterial()
{
    std::cout << "Draw caused by insufficient material for checkmate to be possible!\n" << std::endl;
}

void MoveDialog::ShowMovePutsKingInCheck()
{
    std::cout << "This move will put your king in check! Please try again\n" << std::endl;
}

void MoveDialog::ShowIllegalCastling()
{
    std::cout << "Attempted castle move is illegal! Please try again\n" << std::endl;
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
    
    moveHistoryString += "\n";
    return moveHistoryString;
}
