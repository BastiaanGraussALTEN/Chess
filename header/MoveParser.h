#pragma once

#include "Move.h"
#include "LegalityChecker.h"

class MoveParser
{
    public:
        MoveParser(const Board& board); 
        Move ParseString(const std::string& moveString) const;
        bool IsStringValid(const std::string& moveString) const;
    private:
        Board m_board;
        LegalityChecker m_legalityChecker;
        bool IsStringCastle(const std::string& moveString) const;
        bool IsStringTwoSquares(const std::string& moveString) const;
        bool IsStringPromotion(const std::string& moveString) const;
        void SetMoveSquaresFromString(Move& move, const std::string& moveString) const;
        bool CharIsValidPromotionPiece(const char& piece) const;
        PieceType CharToPieceType(const char& piece) const;
};