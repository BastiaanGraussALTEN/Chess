#pragma once

#include "Board.h"

#include <map>
#include <SFML/Graphics.hpp>

class BoardPrinter
{
    public:
        BoardPrinter(const std::vector<std::shared_ptr<Piece>>& pieces, unsigned int squareSize);
        void PrintBoard(sf::RenderWindow& window) const;
    private:
        void CopyPieces(const std::vector<std::shared_ptr<Piece>>& pieces);
        void DrawEmptyChessBoard(sf::RenderTarget& target) const;
        void DrawPieces(sf::RenderTarget& target) const;
        void DrawPieceSprite(sf::RenderTarget& target, const Color& color, const PieceType& pieceType, const sf::Vector2f& position) const;
        std::string PieceToPath(const Color& color, const PieceType& pieceType) const;
        sf::Vector2f SquareToPosition(const Square& square) const;
        std::vector<std::shared_ptr<Piece>> m_pieces;
        sf::RenderStates m_states = sf::RenderStates::Default;
        unsigned int m_squareSize;
        unsigned int m_windowSize;
        sf::Color lightColor;
        sf::Color darkColor;
        mutable std::map<std::string, sf::Texture> m_textureCache;
};