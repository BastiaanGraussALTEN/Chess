#pragma once

#include "Move.h"

class MoveParser
{
    public: 
        Move ParseString(const std::string& moveString) const;
        bool IsStringValid(const std::string& moveString) const;
    private:
        bool IsStringCastle(const std::string& moveString) const;
        bool IsStringTwoSquares(const std::string& moveString) const;
        bool IsStringPromotion(const std::string& moveString) const;
        void SetMoveSquaresFromString(Move& move, const std::string& moveString) const;
        bool CharIsValidPromotionPiece(const char& piece) const;
        PieceType CharToPieceType(const char& piece) const;
};