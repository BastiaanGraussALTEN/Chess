#pragma once

#include "Board.h"

#include <map>
#include <SFML/Graphics.hpp>

class BoardPrinter
{
    public:
        BoardPrinter(const Board& board);
        void PrintBoard() const;
    private:
        void DrawEmptyChessBoard(sf::RenderTarget& target) const;
        void DrawPieces(sf::RenderTarget& target) const;
        void DrawPieceSprite(sf::RenderTarget& target, const Color& color, const PieceType& pieceType, const sf::Vector2f& position) const;
        std::string PieceToPath(const Color& color, const PieceType& pieceType) const;
        sf::Vector2f SquareToPosition(const Square& square) const;
        Board m_board;
        sf::RenderStates m_states = sf::RenderStates::Default;
        unsigned int m_squareSize;
        unsigned int m_windowSize;
        sf::Color lightColor;
        sf::Color darkColor;
        mutable std::map<std::string, sf::Texture> m_textureCache;
};