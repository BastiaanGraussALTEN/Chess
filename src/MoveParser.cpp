#include "MoveParser.h"
#include <map>

bool MoveParser::IsStringValid(const std::string& moveString) const
{
    if (IsStringCastle(moveString))
    {
        return true;
    }
    if ((moveString.size() == 4)
        && IsStringTwoSquares(moveString))
    {
        return true;
    }
    if (IsStringPromotion(moveString))
    {
        return true;
    }

    return false;
}

bool MoveParser::IsStringCastle(const std::string &moveString) const
{
    if ((moveString == "0-0") || moveString == "0-0-0")
    {
        return true;
    }

    return false;
}

bool MoveParser::IsStringTwoSquares(const std::string &moveString) const
{
    if ((moveString[0] - 'a' + 1 > 0)
        && (moveString[0] - 'a' + 1 < 9)
        && (moveString[1] - '0' > 0)
        && (moveString[1] - '0' < 9)
        && (moveString[2] - 'a' + 1 > 0)
        && (moveString[2] - 'a' + 1 < 9)
        && (moveString[3] - '0' > 0)
        && (moveString[3] - '0' < 9))
    {
        return true;
    }

    return false;
}

bool MoveParser::IsStringPromotion(const std::string &moveString) const
{
    std::string lastTwoChars = moveString.substr(moveString.length() - 2);
    return ((moveString.size() == 6) 
            &&(lastTwoChars[0] == '=')
            &&(CharIsValidPromotionPiece(lastTwoChars[1]))
            &&(moveString[0] - 'a' + 1 > 0)
            &&(moveString[0] - 'a' + 1 < 9)
            &&(moveString[1] - '0' > 0)
            &&(moveString[1] - '0' < 9)
            &&(moveString[2] - 'a' + 1 > 0)
            &&(moveString[2] - 'a' + 1 < 9)
            &&((moveString[3] - '0' == 1) ||(moveString[3] - '0' == 8)));
}

void MoveParser::SetMoveSquaresFromString(Move& move, const std::string& moveString) const
{
    move.start.x = moveString[0] - 'a' + 1;
    move.start.y = moveString[1] - '0';
    move.end.x = moveString[2] - 'a' + 1;
    move.end.y = moveString[3] - '0';
}

bool MoveParser::CharIsValidPromotionPiece(const char &piece) const
{
    if ((piece == 'N') 
    || (piece == 'B')
    || (piece == 'R')
    || (piece == 'Q'))
    {
        return true;
    }
    return false;
}

PieceType MoveParser::CharToPieceType(const char &piece) const
{
    if (piece == 'N')
    {
        return PieceType::KnightType;
    }
    if (piece == 'B')
    {
        return PieceType::BishopType;
    }
    if (piece == 'R')
    {
        return PieceType::RookType;
    }
    if (piece == 'Q')
    {
        return PieceType::QueenType;
    }
    return PieceType::PawnType;
}

Move MoveParser::ParseString(const std::string& moveString) const
{
    Move move = Move(Square(1, 1),Square(1, 1));
    if (moveString == "0-0")
    {
        move.promotionOrCastleside = PieceType::KingType;
        return move;
    }
    if (moveString == "0-0-0")
    {
        move.promotionOrCastleside = PieceType::PawnType;
        return move;
    }
    if (moveString.size() == 4)
    {
        SetMoveSquaresFromString(move, moveString);
    }
    if (IsStringPromotion(moveString))
    {
        SetMoveSquaresFromString(move, moveString);
        char piece = moveString.substr(moveString.length() - 2 )[1];
        move.promotionOrCastleside = CharToPieceType(piece);
    }

    return move;
}