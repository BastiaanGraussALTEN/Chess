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
        DrawPiece(window, sf::RenderStates::Default, Color::White, PieceType::Queen);
        window.display();
    }
}

void BoardPrinter::DrawEmptyChessBoard(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int row = 0; row < Constants::boardEnd; ++row) 
    {
        for (int column = 0; column < Constants::boardEnd; ++column) 
        {
            sf::RectangleShape square(sf::Vector2f(m_squareSize, m_squareSize));
            square.setPosition(sf::Vector2f(column * m_squareSize, row * m_squareSize));
            square.setFillColor((row + column) % 2 ? darkColor : lightColor);
            target.draw(square, states);
        }
    }
}

void BoardPrinter::DrawPiece(sf::RenderTarget& target, sf::RenderStates states, const Color& color, const PieceType& pieceType) const
{
    std::string path = PieceToPath(color, pieceType);
    sf::Texture texture;
    if (!texture.loadFromFile(path))
    {
        std::cerr << "Failed to load " + path << std::endl;
    }

    texture.setSmooth(true);
    sf::Sprite sprite(texture);

    sf::Vector2u textureSize = texture.getSize();
    float scaleX = (float)m_squareSize / textureSize.x;
    float scaleY = (float)m_squareSize / textureSize.y;
    sprite.setScale(sf::Vector2f(scaleX, scaleY));

    target.draw(sprite);
}

std::string BoardPrinter::PieceToPath(const Color& color, const PieceType& pieceType) const
{
    if (color == Color::White)
    {
        switch(pieceType)
        {
            case PieceType::Pawn:
                return "../textures/Chess_WP.png";
                break;
            case PieceType::Knight:
                return "../textures/Chess_WN.png";
                break;
            case PieceType::Bishop:
                return "../textures/Chess_WB.png";
                break;
            case PieceType::Rook:
                return "../textures/Chess_WR.png";
                break;
            case PieceType::Queen:
                return "../textures/Chess_WQ.png";
                break;
            case PieceType::King:
                return "../textures/Chess_WK.png";
                break;
            default:
                return "";
        }
    }
    else
    {
        switch(pieceType)
        {
            case PieceType::Pawn:
                return "../textures/Chess_BP.png";
                break;
            case PieceType::Knight:
                return "../textures/Chess_BN.png";
                break;
            case PieceType::Bishop:
                return "../textures/Chess_BB.png";
                break;
            case PieceType::Rook:
                return "../textures/Chess_BR.png";
                break;
            case PieceType::Queen:
                return "../textures/Chess_BQ.png";
                break;
            case PieceType::King:
                return "../textures/Chess_BK.png";
                break;
            default:
                return "";
        }
    }

    return "";
}