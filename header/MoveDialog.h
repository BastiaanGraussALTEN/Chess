#pragma once

#include <iostream>
#include <vector>
#include "Color.h"

class MoveDialog
{
    public:
        MoveDialog();
        void SetMove(std::string move);
        void ShowDialog();
        void ShowMoveHistory();
        void ShowStringNotValid();
        void ShowMoveNotLegal();
        void ShowPieceWrongColor();
        void ShowCheckMate();
        void ShowStaleMate();
        void Show50MoveDraw();
        void ShowThreeFoldRepetition();
        void ShowMovePutsKingInCheck();
        void ShowIllegalCastling();
        Color GetCurrentTurn();
    private:
        int m_moveNumber;
        std::vector<std::string> m_moveHistory;
        std::string GetMoveHistory();
        std::string GetSingleLineDialog();
};