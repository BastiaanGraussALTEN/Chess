#ifndef MOVEDIALOG_H
#define MOVEDIALOG_H

#include <iostream>
#include <vector>
#include "Color.h"

class MoveDialog
{
    private:
        int m_moveNumber;
        std::vector<std::string> m_moveHistory;
        std::string GetMoveHistory();
        std::string GetSingleLineDialog();
    public:
        MoveDialog();
        void SetMove(std::string move);
        void ShowDialog();
        void ShowErrorText();
        Color GetCurrentTurn();
};

#endif