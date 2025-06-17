#include "MoveParser.h"
#include <map>

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