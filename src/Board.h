#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "PieceFactory.h"

class Board
{
    public:
        const std::vector<std::shared_ptr<Piece>>& GetPieces() const;
        void AddPiece(const std::shared_ptr<Piece>& piece);
        void RemovePiece(const Coord& coord);
    private:
        std::vector<std::shared_ptr<Piece>> m_pieces;
};

#endif