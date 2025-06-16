#ifndef LEGALITYCHECKER_H
#define LEGALITYCHECKER_H

#include "Board.h"

class LegalityChecker
{
    public:
        LegalityChecker(const Board& board);
        bool CheckMoveLegality(const Move& move) const;
        bool DoesMoveCapturePiece(const Move& move) const;
    private:
        bool IsPieceInDiagonal(const Move& move) const;
        bool IsPieceInLine(const Move& move) const;
        bool IsEnPassant(const Move& move, std::shared_ptr<Pawn> pawn) const;
        Board m_board;
};

#endif