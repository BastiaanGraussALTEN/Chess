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
        DrawPieces(window, sf::RenderStates::Default);
        window.display();
    }
}

void BoardPrinter::DrawEmptyChessBoard(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int row = 0; row < Constants::boardEnd; ++row) 
    {
        for (int column = 0; column < Constants::boardEnd; ++column) 
        {
            sf::RectangleShape squareShape(sf::Vector2f(m_squareSize, m_squareSize));
            squareShape.setPosition(sf::Vector2f(column * m_squareSize, row * m_squareSize));
            squareShape.setFillColor((row + column) % 2 ? darkColor : lightColor);
            target.draw(squareShape, states);
        }
    }
}

void BoardPrinter::DrawPieces(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const auto& piece : m_board.GetPieces())
    {
        sf::Vector2f position = SquareToPosition(piece->position);
        DrawPieceSprite(target, states, piece->color, piece->pieceType, position);
    }
}

void BoardPrinter::DrawPieceSprite(sf::RenderTarget& target, sf::RenderStates states, const Color& color, const PieceType& pieceType, const sf::Vector2f& position) const
{
    std::string path = PieceToPath(color, pieceType);

    auto it = m_textureCache.find(path);
    if (it == m_textureCache.end())
    {
        sf::Texture texture;
        if (!texture.loadFromFile(path))
        {
            std::cerr << "Failed to load " << path << std::endl;
            return;
        }
        texture.setSmooth(true);
        m_textureCache[path] = texture;
        it = m_textureCache.find(path);
    }

    const sf::Texture& texture = it->second;
    sf::Sprite sprite(texture);

    sf::Vector2u textureSize = texture.getSize();
    float scaleX = static_cast<float>(m_squareSize) / textureSize.x;
    float scaleY = static_cast<float>(m_squareSize) / textureSize.y;
    sprite.setScale(sf::Vector2f(scaleX, scaleY));

    sprite.setPosition(position);
    target.draw(sprite, states);
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

sf::Vector2f BoardPrinter::SquareToPosition(const Square& square) const
{
    float x = (square.x - 1) * m_squareSize;
    float y = (7 - (square.y - 1)) * m_squareSize;
    return sf::Vector2f(x, y);
}