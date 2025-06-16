#include <algorithm>
#include "LegalityChecker.h"
#include "PositionFunctions.h"

LegalityChecker::LegalityChecker(const Board& board) : m_board(board)
{
}

bool LegalityChecker::CheckMoveLegality(const Move& move) const
{
    // there needs to be a piece on the start square
    auto piece = m_board.GetPieceFromSquare(move.start);
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
    auto pieceOnEnd = m_board.GetPieceFromSquare(move.end);
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
        // if diagonal
        auto pawn = std::dynamic_pointer_cast<Pawn>(piece);
        if (PositionFunctions::IsMoveDiagonal(move))
        {
            // en pessant for white
            if ((piece->color == Color::White) 
            && (piece->position.y == 5) 
            && ((m_board.GetLastMove() == Move(Square(move.end.x, move.end.y + 1), Square(move.end.x, move.end.y - 1)))))
            {
                return true;
            }
            // en pessant for black
            if ((piece->color == Color::Black) 
            && (piece->position.y == 4) 
            && ((m_board.GetLastMove() == Move(Square(move.end.x, move.end.y - 1), Square(move.end.x, move.end.y + 1)))))
            {
                return true;
            }

            // has to capture
            if(pieceOnEnd == nullptr)
            {
                return false;
            }
            // cant capture own piece
            if(pieceOnEnd->color == piece->color)
            {
                return false;
            }
        }
        else
        {
            // cant capture piece in front
            if(pieceOnEnd != nullptr)
            {
                return false;
            }
            // can only walk twice if it is pawns first move
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
    auto piece = m_board.GetPieceFromSquare(move.start);
    auto pieceOnEnd = m_board.GetPieceFromSquare(move.end);
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

    std::vector<Square> inBetweenSquares = PositionFunctions::GetDiagonalsInBetween(move, amountOfInBetweenSquares);
    
    for (const Square& square : inBetweenSquares)
    {
        auto pieceOnSquare = m_board.GetPieceFromSquare(square);
        if (pieceOnSquare != nullptr)
        {
            return true;
        }
    }

    return false;
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

    std::vector<Square> inBetweenSquares = PositionFunctions::GetOrthogonalsInBetween(move, amountOfInBetweenSquares);
    
    for (const Square& square : inBetweenSquares)
    {
        auto pieceOnSquare = m_board.GetPieceFromSquare(square);
        if (pieceOnSquare != nullptr)
        {
            return true;
        }
    }

    return false;
}
