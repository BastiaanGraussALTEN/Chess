#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "PieceFactory.h"
#include "Move.h"

class Board
{
    public:
        Board();
        const std::vector<std::shared_ptr<Piece>>& GetPieces() const;
        void AddPiece(const std::shared_ptr<Piece>& piece);
        void RemovePiece(const Square& coord);
        void MovePiece(const Move& move);
        std::shared_ptr<Piece> GetPieceFromCoord(const Square& coord) const;
    private:
        std::vector<std::shared_ptr<Piece>> m_pieces;
        void CreateInitialBoardState();
};

#endif