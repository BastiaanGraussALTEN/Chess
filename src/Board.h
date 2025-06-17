#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "PieceFactory.h"
#include "Move.h"

class Board
{
    public:
        Board();
        Board(const Board& other);
        const std::vector<std::shared_ptr<Piece>>& GetPieces() const;
        const std::vector<std::shared_ptr<Piece>> GetColorPieces(const Color& pieceColor) const;
        void AddPiece(const std::shared_ptr<Piece>& piece);
        void RemovePieceFromSquare(const Square& coord);
        void MovePiece(const Move& move);
        std::shared_ptr<Piece> GetPieceFromSquare(const Square& coord) const;
        Move GetLastMove() const;
    private:
        Move m_lastMove;
        std::vector<std::shared_ptr<Piece>> m_pieces;
        void CreateInitialBoardState();
};

#endif