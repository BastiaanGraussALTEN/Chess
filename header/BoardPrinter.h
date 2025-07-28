#pragma once

#include "Board.h"

#include <SFML/Graphics.hpp>

class BoardPrinter
{
    public:
        BoardPrinter(const Board& board);
        void PrintBoard() const;
    private:
        void DrawChessBoard(sf::RenderTarget& target, sf::RenderStates states) const;
        void DrawPieceSprite(sf::RenderTarget& target, sf::RenderStates states, const Color& color, const PieceType& pieceType, const sf::Vector2f& position) const;
        std::string PieceToPath(const Color& color, const PieceType& pieceType) const;
        sf::Vector2f SquareToPosition(const Square& square) const;
        Board m_board;
        unsigned int m_squareSize;
        unsigned int m_windowSize;
        sf::Color lightColor;
        sf::Color darkColor;
};