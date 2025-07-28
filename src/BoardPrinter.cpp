#include "../header/BoardPrinter.h"
#include "../header/Constants.h"

#include <SFML/Graphics.hpp>
#include <iostream>

BoardPrinter::BoardPrinter(const Board& board) 
    : m_board(board), 
    m_squareSize(80),
    lightColor(240, 217, 181),
    darkColor(181, 136, 99)
{
    m_windowSize = m_squareSize * 8;
}

void BoardPrinter::PrintBoard() const
{
    auto window = sf::RenderWindow(sf::VideoMode({m_windowSize, m_windowSize}), "Chessboard");
    window.setFramerateLimit(144);

    sf::Texture texture;
    if (!texture.loadFromFile("../textures/Chess_BB.png"))
    {
        std::cerr << "Failed to load Chess_BB.png" << std::endl;
    }

    texture.setSmooth(true);
    sf::Sprite sprite(texture);
        
    sf::Vector2u textureSize = texture.getSize();
    float scaleX = (float)m_squareSize / textureSize.x;
    float scaleY = (float)m_squareSize / textureSize.y;
    sprite.setScale(sf::Vector2f(scaleX, scaleY));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        DrawEmptyChessBoard(window, sf::RenderStates::Default);
        window.draw(sprite);
        window.display();
    }
}

void BoardPrinter::DrawEmptyChessBoard(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int row = 0; row < size; ++row) 
    {
        for (int column = 0; column < size; ++column) 
        {
            sf::RectangleShape square(sf::Vector2f(m_squareSize, m_squareSize));
            square.setPosition(sf::Vector2f(column * m_squareSize, row * m_squareSize));
            square.setFillColor((row + column) % 2 ? darkColor : lightColor);
            target.draw(square, states);
        }
    }
}