#ifndef LEGALITYCHECKER_H
#define LEGALITYCHECKER_H

#include "Board.h"

class LegalityChecker
{
    public:
        LegalityChecker(const Board& board);
        bool CheckMoveLegality(const Move& move) const;
        bool DoesMoveCapturePiece(const Move& move) const;
        bool IsMoveDiagonal(const Move& move) const;
    private:
        bool IsMoveOrthogonal(const Move& move) const;
        bool IsPieceInDiagonal(const Move& move) const;
        bool IsPieceInLine(const Move& move) const;
        std::vector<Square> GetDiagonalsInBetween(const Move &move, int amoundtOfInBetweenSteps) const;
        std::vector<Square> GetOrthogonalsInBetween(const Move &move, int amoundtOfInBetweenSteps) const;
        Board m_board;
};

#endif