#include "../header/CheckChecker.h"

#include <vector>

CheckChecker::CheckChecker(const Board &board, const Color &color)
: m_board(board), m_color(color)
{
}

bool CheckChecker::IsKingSafeAfterMove(const Move &move) const
{
    Board boardCopy = m_board;
    if (boardCopy.GetPieceFromSquare(move.end) != nullptr)
    {
        boardCopy.RemovePieceFromSquare(move.end);
    }
    boardCopy.MovePiece(move);
    LegalityChecker legalityChecker(boardCopy);
    DangerChecker dangerChecker(boardCopy, m_color);
    return !dangerChecker.IsKingUnderAttack();
}

bool CheckChecker::EveryMoveChecksSelf() const
{
    LegalityChecker legalityChecker = LegalityChecker(m_board);
    std::vector<Move> possibleMoves = legalityChecker.GetAllPossibleMoves(m_color);
    for (const Move& move : possibleMoves)
    {
        if (IsKingSafeAfterMove(move))
        {
            return false;
        }
    }

    return true;
}

bool CheckChecker::SufficientMaterialForCheckmate() const
{
    // there are mating pieces
    for (const auto& piece : m_board.GetPieces())
    {
        if (piece->pieceType == PieceType::Pawn || piece->pieceType == PieceType::Rook || piece->pieceType == PieceType::Queen)
        {
            return true;
        }
    }

    // there are only kings and potentially one knight/bishop as piece
    if (m_board.GetPieces().size() < 4)
    {
        return false;
    }
    
    // insufficient material if and only if 2 bishops of different color on the same color
    if (m_board.GetPieces().size() == 4)
    {
        std::vector<std::shared_ptr<Piece>> bishops;
        for (const auto& piece : m_board.GetPieces())
        {
            if (piece->pieceType == PieceType::Bishop)
            {
                bishops.push_back(piece);
            }
        }
        if (bishops.size() == 2 && bishops[0]->color != bishops[1]->color && PiecesAreOnSameColor(bishops[0], bishops[1]))
        {
            return false;
        }
    }

    return true;
}
bool CheckChecker::PiecesAreOnSameColor(const std::shared_ptr<Piece>& piece1, const std::shared_ptr<Piece>& piece2) const
{
    return (piece1->position.x % 2 
        + piece1->position.y % 2 
        + piece2->position.x % 2 
        + piece2->position.y % 2 ) % 2 == 0;
}