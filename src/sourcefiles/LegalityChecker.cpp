#include <algorithm>
#include "../headerfiles/LegalityChecker.h"
#include "../headerfiles/PositionFunctions.h"

LegalityChecker::LegalityChecker(const Board& board) : m_board(board)
{
}

bool LegalityChecker::CheckMoveLegality(const Move& move) const
{
    auto piece = m_board.GetPieceFromSquare(move.start);
    if (piece == nullptr)
    {
        return false;
    }

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

    auto pieceOnEnd = m_board.GetPieceFromSquare(move.end);
    if (pieceOnEnd != nullptr)
    {
        if(pieceOnEnd->color == piece->color)
        {
            return false;
        }
    }

    if (piece->pieceType == PieceType::Pawn)
    {
        if (PositionFunctions::IsMoveDiagonal(move))
        {
            if (IsEnPassant(move, piece))
            {
                return true;
            }

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
            
            if(abs(move.end.y - move.start.y) == 2 && piece->hasMoved == true)
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

std::vector<Move> LegalityChecker::GetAllPossibleMoves(const Color& color) const
{
    std::vector<Move> possibleMoves;
    std::vector<std::shared_ptr<Piece>> pieces = m_board.GetColorPieces(color);
    for (const auto& piece : pieces)
    {
        Square beginPosition = piece->position;
        std::vector<Square> allPossibleEndSquares =  piece->GetPossibleMoves();
        for (const Square& endPosition : allPossibleEndSquares)
        {
            if (CheckMoveLegality(Move(beginPosition, endPosition)))
            {
                possibleMoves.push_back(Move(beginPosition, endPosition));
            }
        }
    }

    return possibleMoves;
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

bool LegalityChecker::IsEnPassant(const Move &move, std::shared_ptr<Piece> pawn) const
{
    if ((pawn->color == Color::White) 
    && (pawn->position.y == 5) 
    && ((m_board.GetLastMove() == Move(Square(move.end.x, move.end.y + 1), Square(move.end.x, move.end.y - 1)))))
    {
        return true;
    }

    if ((pawn->color == Color::Black) 
    && (pawn->position.y == 4) 
    && ((m_board.GetLastMove() == Move(Square(move.end.x, move.end.y - 1), Square(move.end.x, move.end.y + 1)))))
    {
        return true;
    } 

    return false;
}
