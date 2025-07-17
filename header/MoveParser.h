#pragma once

#include "Move.h"
#include "LegalityChecker.h"

class MoveParser
{
    public:
        MoveParser(const Board& board, const Color& color); 
        Move ParseString(const std::string& moveString) const;
    private:
        Board m_board;
        Color m_color;
        LegalityChecker m_legalityChecker;
        std::vector<Move> GetPossibleMovesWithEndSquare(const std::string& moveString, const Move& move) const;
        std::vector<Move> ElimateMovesBasedOnStartSquareInfo(std::vector<Move> possibleMoves, const std::string& moveStringBegin) const;
        bool IsStringPromotion(const std::string& moveString) const;
        Square stringToSquare(const std::string& moveString) const;
        bool IsStringSquare(const std::string& moveString) const;
        bool CharIsValidPromotionPiece(const char& piece) const;
        bool IsPromotion(const Move& move) const;
        PieceType CharToPieceType(const char& piece) const;
};