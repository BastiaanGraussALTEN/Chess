#include <algorithm>
#include <iostream>

#include "../header/Board.h"
#include "../header/Constants.h"

Board::Board()
: m_lastMove(Square(1, 1), Square(1, 1))
{
    CreateInitialBoardState();
    m_consecutiveNonCaptures = 0;
    m_consecutiveNonPawnMoves = 0;
    WhiteHasKingsideCastleRights = true;
    WhiteHasQueensideCastleRights = true;
    BlackHasKingsideCastleRights = true;
    BlackHasQueensideCastleRights = true;
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

bool Board::operator==(const Board &rhs) const
{
    if (this->m_pieces.size() != rhs.m_pieces.size()) 
    {
        return false;
    }

    for (size_t i = 0; i < m_pieces.size(); i++) 
    {
        if (!AreSharedPointersEqual(m_pieces[i], rhs.m_pieces[i]))
        {
            return false;
        }
    }

    return this->EnPessantSquare == rhs.EnPessantSquare
    && this->WhiteHasKingsideCastleRights == rhs.WhiteHasKingsideCastleRights
    && this->WhiteHasQueensideCastleRights == rhs.WhiteHasQueensideCastleRights
    && this->BlackHasKingsideCastleRights == rhs.BlackHasKingsideCastleRights
    && this->BlackHasQueensideCastleRights == rhs.BlackHasQueensideCastleRights;
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
    return std::any_of(m_pieces.begin(), m_pieces.end(),
    [&](const auto& piece) {
        return piece->color == pieceColor && piece->position == square;
    });
}

bool Board::IsFiftyMoveRule()
{
    return m_consecutiveNonCaptures > 99 && m_consecutiveNonPawnMoves > 99;
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
        UpdateCastleRights(move, piece);
        piece->position = move.end;
        piece->hasMoved = true;
        m_lastMove = move;
    }

    if (piece->pieceType == PieceType::Pawn)
    {
        UpdateEnPessantState(move, piece);
    }
    else
    {
        UpdateVarsAfterNonPawnMove();
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
        if (piece->position == coord)
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

bool Board::AreSharedPointersEqual(const std::shared_ptr<Piece>& lhs, const std::shared_ptr<Piece>& rhs) const
{
    if (!lhs && !rhs)
    {
        return true;
    } 
    if (!lhs || !rhs)
    {
        return false;
    }

    return *lhs == *rhs;
}

void Board::CreateInitialBoardState()
{
    CreateInitialPawns();
    CreateInitialWhitePieces();
    CreateInitialBlackPieces();
}

void Board::CreateInitialPawns()
{
    for (int i = Constants::boardBegin; i < Constants::boardEnd + 1; i++)
    {
        AddPiece(PieceFactory::CreatePawn(Color::White, Square(i, 2)));
        AddPiece(PieceFactory::CreatePawn(Color::Black, Square(i, 7)));
    }
}

void Board::CreateInitialWhitePieces()
{
    AddPiece(PieceFactory::CreateRook(Color::White, Square(1, 1)));
    AddPiece(PieceFactory::CreateKnight(Color::White, Square(2, 1)));
    AddPiece(PieceFactory::CreateBishop(Color::White, Square(3, 1)));
    AddPiece(PieceFactory::CreateQueen(Color::White, Square(4, 1)));
    AddPiece(PieceFactory::CreateKing(Color::White, Square(5, 1)));
    AddPiece(PieceFactory::CreateBishop(Color::White, Square(6, 1)));
    AddPiece(PieceFactory::CreateKnight(Color::White, Square(7, 1)));
    AddPiece(PieceFactory::CreateRook(Color::White, Square(8, 1)));
}

void Board::CreateInitialBlackPieces()
{
    AddPiece(PieceFactory::CreateRook(Color::Black, Square(1, 8)));
    AddPiece(PieceFactory::CreateKnight(Color::Black, Square(2, 8)));
    AddPiece(PieceFactory::CreateBishop(Color::Black, Square(3, 8)));
    AddPiece(PieceFactory::CreateQueen(Color::Black, Square(4, 8)));
    AddPiece(PieceFactory::CreateKing(Color::Black, Square(5, 8)));
    AddPiece(PieceFactory::CreateBishop(Color::Black, Square(6, 8)));
    AddPiece(PieceFactory::CreateKnight(Color::Black, Square(7, 8)));
    AddPiece(PieceFactory::CreateRook(Color::Black, Square(8, 8)));
}

void Board::UpdateEnPessantState(const Move &move, const std::shared_ptr<Piece> &piece)
{
    m_consecutiveNonPawnMoves = 0;
    if (abs(move.end.y - move.start.y) == 2)
    {
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
        EnPessantSquare = Square(1,1);
    }
}

void Board::UpdateVarsAfterNonPawnMove()
{
    m_consecutiveNonPawnMoves += 1;
    EnPessantSquare = Square(1,1);
}

void Board::UpdateCastleRights(const Move& move, const std::shared_ptr<Piece>& piece)
{
    if (piece->pieceType == PieceType::King && piece->hasMoved == false && piece->color == Color::White)
        {   
            WhiteHasKingsideCastleRights = false;
            WhiteHasQueensideCastleRights = false;
        }
        if (piece->pieceType == PieceType::King && piece->hasMoved == false && piece->color == Color::Black)
        {   
            BlackHasKingsideCastleRights = false;
            BlackHasQueensideCastleRights = false;
        }
        if (piece->pieceType == PieceType::Rook && piece->hasMoved == false && piece->color == Color::White && piece->position.x == 1)
        {   
            WhiteHasKingsideCastleRights = false;
        }
        if (piece->pieceType == PieceType::Rook && piece->hasMoved == false && piece->color == Color::White && piece->position.x == 8)
        {   
            WhiteHasQueensideCastleRights = false;
        }
        if (piece->pieceType == PieceType::Rook && piece->hasMoved == false && piece->color == Color::Black && piece->position.x == 1)
        {   
            BlackHasKingsideCastleRights = false;
        }
        if (piece->pieceType == PieceType::Rook && piece->hasMoved == false && piece->color == Color::Black && piece->position.x == 8)
        {   
            BlackHasQueensideCastleRights = false;
        }
}
