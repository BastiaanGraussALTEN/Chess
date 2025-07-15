#pragma once

#include "Move.h"
#include "LegalityChecker.h"

class MoveParser
{
    public:
        MoveParser(const Board& board); 
        Move ParseString(const std::string& moveString) const;
    private:
        Board m_board;
        LegalityChecker m_legalityChecker;
        bool IsStringTwoSquares(const std::string& moveString) const;
        bool IsStringPromotion(const std::string& moveString) const;
        Square stringToSquare(const std::string& moveString) const;
        bool IsStringSquare(const std::string& moveString) const;
        bool CharIsValidPromotionPiece(const char& piece) const;
        bool IsPromotion(const Move& move) const;
        PieceType CharToPieceType(const char& piece) const;
};