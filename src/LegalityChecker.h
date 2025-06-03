#ifndef LEGALITYCHECKER_H
#define LEGALITYCHECKER_H

#include "Board.h"
#include "Move.cpp"

class LegalityChecker
{
    public:
        LegalityChecker(const Board& board);
        bool CheckMoveLegality(const Move& move) const;
    private:
        bool IsMoveDiagonal(const Move& move) const;
        bool IsMoveOrthogonal(const Move& move) const;
        bool IsPieceInDiagonal(const Move& move) const;
        bool IsPieceInLine(const Move& move) const;
        std::vector<Square> GetDiagonalsInBetween(const Move &move, int amoundtOfInBetweenSteps) const;
        Board m_board;
};

#endif