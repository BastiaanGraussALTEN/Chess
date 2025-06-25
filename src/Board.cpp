#include "Board.h"

Board::Board()
: m_lastMove(Square(1, 1), Square(1, 1))
{
    CreateInitialBoardState();
    m_consecutiveNonCaptures = 0;
    m_consecutiveNonPawnMoves = 0;
    HasEnPessantSquare = false;
}

Board::Board(const Board &other) : m_lastMove(other.m_lastMove)
{
    m_pieces.reserve(other.m_pieces.size());
    for (const auto& piecePtr : other.m_pieces) 
    {
        if (piecePtr) 
        {
            m_pieces.push_back(piecePtr->clone());
        } 
        else 
        {
            m_pieces.push_back(nullptr);
        }
    }
}

const std::vector<std::shared_ptr<Piece>>& Board::GetPieces() const
{
    return m_pieces;
}

const std::vector<std::shared_ptr<Piece>> Board::GetColorPieces(const Color &pieceColor) const
{
    std::vector<std::shared_ptr<Piece>> colorPieces; 
    for (auto piece : m_pieces)
    {
        if (piece->color == pieceColor)
        {
            colorPieces.push_back(piece);
        }
    }

    return colorPieces;
}

bool Board::IsThereAPieceOfThisColorHere(const Color &pieceColor, const Square &square) const
{
    for (auto piece : m_pieces)
    {
        if ((piece->color == pieceColor)
        && (piece->position == square))
        {
            return true;
        }
    }

    return false;
}

bool Board::IsFiftyMoveRule()
{
    if ((m_consecutiveNonCaptures > 99) 
    && (m_consecutiveNonPawnMoves > 99))
    {
        return true;
    }

    return false;
}

void Board::AddPiece(const std::shared_ptr<Piece> &piece)
{
    for (const auto& boardPiece : m_pieces)
    {
        if ( boardPiece->position == piece->position)
        {
            throw std::invalid_argument("there is a piece already on this square");
        }
    }

    m_pieces.push_back(piece);
}

void Board::RemovePieceFromSquare(const Square &coord)
{
    for (int i = 0; i < m_pieces.size(); i++)
    {
        if (m_pieces[i]->position == coord)
        {
            m_pieces.erase( m_pieces.begin() + i );
        }
    }

    m_consecutiveNonCaptures = -1;
}

void Board::MovePiece(const Move &move)
{
    auto piece = GetPieceFromSquare(move.start);
    if (piece == nullptr)
    {
        throw std::invalid_argument("there is no piece on this square");
    }
    else
    {
        piece->position = move.end;
        piece->hasMoved = true;
        m_lastMove = move;
    }

    if (piece->pieceType == PieceType::PawnType)
    {
        m_consecutiveNonPawnMoves = 0;
        if (abs(move.end.y - move.start.y) == 2)
        {
            HasEnPessantSquare = true;
            if (piece->color == Color::White)
            {
                EnPessantSquare = Square(move.end.x, move.end.y - 1);
            }
            if (piece->color == Color::Black)
            {
                EnPessantSquare = Square(move.end.x, move.end.y + 1);
            }
        }
        else
        {
            HasEnPessantSquare = false;
            EnPessantSquare = Square(1,1);
        }
    }
    else
    {
        m_consecutiveNonPawnMoves += 1;
        HasEnPessantSquare = false;
        EnPessantSquare = Square(1,1);
    }

    m_consecutiveNonCaptures += 1;
}

void Board::CastleKingside(const Color &color)
{
    int file = 1;
    if (color == Color::Black)
    {
        file = 8;
    }

    MovePiece(Move(Square(5, file), Square(7, file)));
    MovePiece(Move(Square(8, file), Square(6, file)));
}

void Board::CastleQueenside(const Color &color)
{
    int file = 1;
    if (color == Color::Black)
    {
        file = 8;
    }

    MovePiece(Move(Square(5, file), Square(3, file)));
    MovePiece(Move(Square(1, file), Square(4, file)));
}

std::shared_ptr<Piece> Board::GetPieceFromSquare(const Square &coord) const
{
    for (const auto& piece : m_pieces)
    {
        if ( piece->position == coord)
        {
            return piece;
        }
    }

    return nullptr;
}

Move Board::GetLastMove() const
{
    return m_lastMove;
}

void Board::CreateInitialBoardState()
{
    // Create pawns
    for (int i = 1; i < 9; i++)
    {
        AddPiece(PieceFactory::CreatePawn(Color::White, Square(i, 2)));
        AddPiece(PieceFactory::CreatePawn(Color::Black, Square(i, 7)));
    }

    // Create white pieces
    AddPiece(PieceFactory::CreateRook(Color::White, Square(1, 1)));
    AddPiece(PieceFactory::CreateKnight(Color::White, Square(2, 1)));
    AddPiece(PieceFactory::CreateBishop(Color::White, Square(3, 1)));
    AddPiece(PieceFactory::CreateQueen(Color::White, Square(4, 1)));
    AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    AddPiece(PieceFactory::CreateBishop(Color::White, Square(6, 1)));
    AddPiece(PieceFactory::CreateKnight(Color::White, Square(7, 1)));
    AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 1)));
    
    // Create black pieces
    AddPiece(PieceFactory::CreateRook(Color::Black, Square(1, 8)));
    AddPiece(PieceFactory::CreateKnight(Color::Black, Square(2, 8)));
    AddPiece(PieceFactory::CreateBishop(Color::Black, Square(3, 8)));
    AddPiece(PieceFactory::CreateQueen(Color::Black, Square(4, 8)));
    AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    AddPiece(PieceFactory::CreateBishop(Color::Black, Square(6, 8)));
    AddPiece(PieceFactory::CreateKnight(Color::Black, Square(7, 8)));
    AddPiece(PieceFactory::CreateRook(Color::Black, Square(8, 8)));
}
