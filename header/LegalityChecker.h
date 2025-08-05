#pragma once

#include "Board.h"

class LegalityChecker
{
    public:
        LegalityChecker(const Board& board);
        bool CheckMoveLegality(const Move& move) const;
        bool DoesMoveCapturePiece(const Move& move) const;
        bool IsEnPassant(const Move& move, std::shared_ptr<Piece> pawn) const;
        std::vector<Move> GetAllPossibleMoves(const Color& color) const;
    private:
        bool IsPieceInDiagonal(const Move& move) const;
        bool IsPieceInLine(const Move& move) const;
        Board m_board;
};