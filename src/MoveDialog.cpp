#include "MoveDialog.h"

MoveDialog::MoveDialog()
{
    m_move_number = 0;
}

void MoveDialog::SetMove(std::string move)
{
    m_move_number += 1;
}

std::string MoveDialog::GetDialog()
{
    if (m_move_number % 2 == 0)
    {
        return "White to move";
    }
    else
    {
        return "Black to move";
    }
}
