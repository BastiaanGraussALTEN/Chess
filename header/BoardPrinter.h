#pragma once

#include "Board.h"

class BoardPrinter
{
    public:
        BoardPrinter(const Board& board);
        void PrintBoard() const;
    private:
        Board m_board;
        std::string PieceToUnicode(const std::shared_ptr<Piece>& piece) const;
};