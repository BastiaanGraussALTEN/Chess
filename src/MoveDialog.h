#ifndef MOVEDIALOG_H
#define MOVEDIALOG_H

#include <iostream>
#include <vector>
#include "Color.h"

class MoveDialog
{
    public:
        MoveDialog();
        void SetMove(std::string move);
        void ShowDialog();
        void ShowErrorText();
        void ShowStringNotValid();
        void ShowMoveNotLegal();
        void ShowPieceWrongColor();
        Color GetCurrentTurn();
    private:
        int m_moveNumber;
        std::vector<std::string> m_moveHistory;
        std::string GetMoveHistory();
        std::string GetSingleLineDialog();
};

#endif