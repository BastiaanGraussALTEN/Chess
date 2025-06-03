#include <algorithm>
#include "LegalityChecker.h"

LegalityChecker::LegalityChecker(const Board& board) : m_board(board)
{
}

bool LegalityChecker::CheckMoveLegality(const Move& move) const
{
    auto piece = m_board.GetPieceFromCoord(move.start);
    std::vector<Square> possibleMoves = piece->GetPossibleMoves();
    if (std::find(possibleMoves.begin(), possibleMoves.end(), move.end) == possibleMoves.end())
    {
        return false;
    }
    if (IsMoveDiagonal(move))
    {
        if(IsPieceInDiagonal(move))
        {
            return false;
        }
    }
    if (IsMoveOrthogonal(move))
    {
        if(IsPieceInLine(move))
        {
            return false;
        }
    }
    return true;
}

bool LegalityChecker::IsMoveDiagonal(const Move &move) const
{
    if (abs(move.start.x - move.end.x) == abs(move.start.y - move.end.y))
    {
        return true;
    }

    return false;
}

bool LegalityChecker::IsPieceInDiagonal(const Move &move) const
{
    int inBetweenStep = abs(move.end.x - move.start.x) - 1;
    if (inBetweenStep == 0)
    {
        return false;
    }

    std::vector<Square> inBetweenSteps;

    // move is to the right
    if (move.end.x - move.start.x > 0)
    {
        // move is upwards
        if (move.end.y - move.start.y > 0)
        {
            for (int i = 1; i < inBetweenStep + 1; i++)
            {
                inBetweenSteps.push_back(Square(move.start.x + i, move.start.y + i));
            }
        }

        // move is downwards
        if (move.end.y - move.start.y < 0)
        {
            for (int i = 1; i < inBetweenStep + 1; i++)
            {
                inBetweenSteps.push_back(Square(move.start.x + i, move.start.y - i));
            }
        }
    }

    // move is to the left
    if (move.end.x - move.start.x < 0)
    {
        // move is upwards
        if (move.end.y - move.start.y > 0)
        {
            for (int i = 1; i < inBetweenStep + 1; i++)
            {
                inBetweenSteps.push_back(Square(move.start.x - i, move.start.y + i));
            }
        }

        // move is downwards
        if (move.end.y - move.start.y < 0)
        {
            for (int i = 1; i < inBetweenStep + 1; i++)
            {
                inBetweenSteps.push_back(Square(move.start.x - i, move.start.y - i));
            }
        }
    }
    
    for (const Square& square : inBetweenSteps)
    {
        auto pieceOnSquare = m_board.GetPieceFromCoord(square);
        if (pieceOnSquare != nullptr)
        {
            return true;
        }
    }

    return false;
}

bool LegalityChecker::IsMoveOrthogonal(const Move &move) const
{
    if (move.start.x - move.end.x == 0 && move.start.y - move.end.y != 0)
    {
        return true;
    }
    if (move.start.x - move.end.x != 0 && move.start.y - move.end.y == 0)
    {
        return true;
    }

    return false;
}

bool LegalityChecker::IsPieceInLine(const Move &move) const
{
    // create spaces between start and end
    
    // check if there are pieces in the way
    return false;
}
