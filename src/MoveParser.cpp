#include "MoveParser.h"
#include <map>

bool MoveParser::IsStringValid(const std::string& moveString) const
{
    if ((moveString == "0-0") ||moveString == "0-0-0")
    {
        return true;
    }
    if ((moveString.size() == 4)
    && (moveString[0] - 'a' + 1 > 0)
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

Move MoveParser::ParseString(const std::string& moveString) const
{
    Move move = Move(Square(1, 1),Square(1, 1));
    if (moveString.size() == 4)
    {
        move.start.x = moveString[0] - 'a' + 1;
        move.start.y = moveString[1] - '0';
        move.end.x = moveString[2] - 'a' + 1;
        move.end.y = moveString[3] - '0';
    }

    return move;
}