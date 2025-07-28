#pragma once

#include "Board.h"

#include <SFML/Graphics.hpp>

class BoardPrinter
{
    public:
        BoardPrinter(const Board& board);
        void PrintBoard() const;
    private:
        void DrawEmptyChessBoard(sf::RenderTarget& target, sf::RenderStates states) const;
        void DrawPiece(sf::RenderTarget& target, sf::RenderStates states, const Color& color, const PieceType& pieceType) const;
        std::string PieceToPath(const Color& color, const PieceType& pieceType) const;
        Board m_board;
        unsigned int m_squareSize;
        unsigned int m_windowSize;
        sf::Color lightColor;
        sf::Color darkColor;
};