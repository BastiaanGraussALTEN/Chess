#pragma once

#include "PieceFactory.h"
#include "Move.h"

#include <vector>
#include <algorithm>

class Board
{
    public:
        Board();
        Board(const Board& other);
        bool operator==(const Board& rhs) const;
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
        Square EnPessantSquare = Square(1, 1);
        bool WhiteHasKingsideCastleRights;
        bool WhiteHasQueensideCastleRights;
        bool BlackHasKingsideCastleRights;
        bool BlackHasQueensideCastleRights;
    private:
        Move m_lastMove;
        int m_consecutiveNonPawnMoves;
        int m_consecutiveNonCaptures;
        std::vector<std::shared_ptr<Piece>> m_pieces;
        bool AreSharedPointersEqual(const std::shared_ptr<Piece>& lhs, const std::shared_ptr<Piece>& rhs) const;
        void CreateInitialBoardState();
        void CreateInitialPawns();
        void CreateInitialWhitePieces();
        void CreateInitialBlackPieces();
        void UpdateEnPessantState(const Move& move, const std::shared_ptr<Piece>& piece);
        void UpdateVarsAfterNonPawnMove();
        void UpdateCastleRights(const Move& move, const std::shared_ptr<Piece>& piece);
};

namespace std 
{
    template <>
    struct hash<Board> 
    {
        size_t operator()(const Board& b) const noexcept
        {
            size_t h = 0;

            h ^= std::hash<Square>()(b.EnPessantSquare) + 0x9e3779b9 + (h << 6) + (h >> 2);

            h ^= std::hash<bool>()(b.WhiteHasKingsideCastleRights) + 0x9e3779b9 + (h << 6) + (h >> 2);
            h ^= std::hash<bool>()(b.WhiteHasQueensideCastleRights) + 0x9e3779b9 + (h << 6) + (h >> 2);
            h ^= std::hash<bool>()(b.BlackHasKingsideCastleRights) + 0x9e3779b9 + (h << 6) + (h >> 2);
            h ^= std::hash<bool>()(b.BlackHasQueensideCastleRights) + 0x9e3779b9 + (h << 6) + (h >> 2);

            auto sortedPieces = std::vector<std::shared_ptr<Piece>>(b.GetPieces().begin(), b.GetPieces().end());
            std::sort(sortedPieces.begin(), sortedPieces.end(), [](const auto& a, const auto& b) 
            {
                return *a < *b;
            });

            for (const auto& piece_ptr : sortedPieces) 
            {
                h ^= std::hash<Piece>()(*piece_ptr) + 0x9e3779b9 + (h << 6) + (h >> 2);
            }

            return h;
        }
    };
}