#pragma once

#include <vector>
#include "PieceFactory.h"
#include "Move.h"

class Board
{
    public:
        Board();
        Board(const Board& other);
        const std::vector<std::shared_ptr<Piece>>& GetPieces() const;
        const std::vector<std::shared_ptr<Piece>> GetColorPieces(const Color& pieceColor) const;
        bool IsThereAPieceOfThisColorHere(const Color& pieceColor, const Square& square) const;
        bool IsFiftyMoveRule();
        void AddPiece(const std::shared_ptr<Piece>& piece);
        void RemovePieceFromSquare(const Square& coord);
        void MovePiece(const Move& move);
        void CastleKingside(const Color& color);
        void CastleQueenside(const Color& color);
        std::shared_ptr<Piece> GetPieceFromSquare(const Square& coord) const;
        Move GetLastMove() const;
        bool HasEnPessantSquare;
        Square EnPessantSquare = Square(1, 1);
    private:
        Move m_lastMove;
        int m_consecutiveNonPawnMoves;
        int m_consecutiveNonCaptures;
        std::vector<std::shared_ptr<Piece>> m_pieces;
        void CreateInitialBoardState();
        void CreateInitialPawns();
        void CreateInitialWhitePieces();
        void CreateInitialBlackPieces();
        void UpdateEnPessantState(const Move& move, const std::shared_ptr<Piece>& piece);
};