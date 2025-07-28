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
        Board m_board;
        unsigned int m_squareSize;
        unsigned int m_windowSize;
        sf::Color lightColor;
        sf::Color darkColor;
        static const int size = 8;
};