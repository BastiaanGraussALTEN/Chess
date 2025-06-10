#include <algorithm>
#include "LegalityChecker.h"
#include "PositionFunctions.h"

LegalityChecker::LegalityChecker(const Board& board) : m_board(board)
{
}

bool LegalityChecker::CheckMoveLegality(const Move& move) const
{
    // there needs to be a piece on the start square
    auto piece = m_board.GetPieceFromCoord(move.start);
    if (piece == nullptr)
    {
        return false;
    }

    // rook, bishop, queen and pawn cannot jump over pieces
    std::vector<Square> possibleMoves = piece->GetPossibleMoves();
    if (std::find(possibleMoves.begin(), possibleMoves.end(), move.end) == possibleMoves.end())
    {
        return false;
    }
    if (PositionFunctions::IsMoveDiagonal(move))
    {
        if(IsPieceInDiagonal(move))
        {
            return false;
        }
    }
    if (PositionFunctions::IsMoveOrthogonal(move))
    {
        if(IsPieceInLine(move))
        {
            return false;
        }
    }

    // you cant capture your own piece
    auto pieceOnEnd = m_board.GetPieceFromCoord(move.end);
    if (pieceOnEnd != nullptr)
    {
        if(pieceOnEnd->color == piece->color)
        {
            return false;
        }
    }

    // pawn stuff
    if (piece->pieceType == PieceType::PawnType)
    {
        auto pawn = std::dynamic_pointer_cast<Pawn>(piece);
        if (PositionFunctions::IsMoveDiagonal(move))
        {
            if(pieceOnEnd == nullptr)
            {
                return false;
            }
            if(pieceOnEnd->color == piece->color)
            {
                return false;
            }
        }
        else
        {
            if(pieceOnEnd != nullptr)
            {
                return false;
            }
            if(abs(move.end.y - move.start.y) == 2 && pawn->hasMoved == true)
            {
                return false;
            }
        }
    }

    return true;
}

bool LegalityChecker::DoesMoveCapturePiece(const Move &move) const
{
    auto piece = m_board.GetPieceFromCoord(move.start);
    auto pieceOnEnd = m_board.GetPieceFromCoord(move.end);
    if (pieceOnEnd != nullptr)
    {
        if(pieceOnEnd->color != piece->color)
        {
            return true;
        }
    }
    return false;
}

bool LegalityChecker::IsPieceInDiagonal(const Move &move) const
{
    int amountOfInBetweenSquares = abs(move.end.x - move.start.x) - 1;
    if (amountOfInBetweenSquares == 0)
    {
        return false;
    }

    std::vector<Square> inBetweenSquares = GetDiagonalsInBetween(move, amountOfInBetweenSquares);
    
    for (const Square& square : inBetweenSquares)
    {
        auto pieceOnSquare = m_board.GetPieceFromCoord(square);
        if (pieceOnSquare != nullptr)
        {
            return true;
        }
    }

    return false;
}

std::vector<Square> LegalityChecker::GetDiagonalsInBetween(const Move &move, int amoundtOfInBetweenSteps) const
{
    std::vector<Square> inBetweenSteps;
    // move is to the right
    if (move.end.x - move.start.x > 0)
    {
        // move is upwards
        if (move.end.y - move.start.y > 0)
        {
            for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
            {
                inBetweenSteps.push_back(Square(move.start.x + i, move.start.y + i));
            }
        }

        // move is downwards
        if (move.end.y - move.start.y < 0)
        {
            for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
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
            for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
            {
                inBetweenSteps.push_back(Square(move.start.x - i, move.start.y + i));
            }
        }

        // move is downwards
        if (move.end.y - move.start.y < 0)
        {
            for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
            {
                inBetweenSteps.push_back(Square(move.start.x - i, move.start.y - i));
            }
        }
    }

    return inBetweenSteps;
}

bool LegalityChecker::IsPieceInLine(const Move &move) const
{
    int amountOfInBetweenSquares;
    if (move.start.x == move.end.x)
    {
        amountOfInBetweenSquares = abs(move.end.y - move.start.y) - 1;
    }
    if (move.start.y == move.end.y)
    {
        amountOfInBetweenSquares = abs(move.end.x - move.start.x) - 1;
    }
    if (amountOfInBetweenSquares == 0)
    {
        return false;
    }

    std::vector<Square> inBetweenSquares = GetOrthogonalsInBetween(move, amountOfInBetweenSquares);
    
    for (const Square& square : inBetweenSquares)
    {
        auto pieceOnSquare = m_board.GetPieceFromCoord(square);
        if (pieceOnSquare != nullptr)
        {
            return true;
        }
    }

    return false;
}

std::vector<Square> LegalityChecker::GetOrthogonalsInBetween(const Move &move, int amoundtOfInBetweenSteps) const
{
    std::vector<Square> inBetweenSteps;
    // move is to the right
    if (move.end.x - move.start.x > 0)
    {
        for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
        {
            inBetweenSteps.push_back(Square(move.start.x + i, move.start.y));
        }
    }

    // move is to the left
    if (move.end.x - move.start.x < 0)
    {
        for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
        {
            inBetweenSteps.push_back(Square(move.start.x - i, move.start.y));
        }
    }

    // move is upwards
    if (move.end.y - move.start.y > 0)
    {
        for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
        {
            inBetweenSteps.push_back(Square(move.start.x, move.start.y + i));
        }
    }

    // move is downwards
    if (move.end.y - move.start.y < 0)
    {
        for (int i = 1; i < amoundtOfInBetweenSteps + 1; i++)
        {
            inBetweenSteps.push_back(Square(move.start.x, move.start.y - i));
        }
    }

    return inBetweenSteps;
}
