#include "../header/BoardPrinter.h"
#include "../header/Constants.h"

#include <SFML/Graphics.hpp>
#include <iostream>

BoardPrinter::BoardPrinter(const Board& board) : m_board(board)
{
}

void BoardPrinter::PrintBoard() const
{
    for(int i = Constants::boardEnd; i > Constants::boardBegin - 1; i--)
    {
        std::string row = std::to_string(i);
        for (int j = Constants::boardBegin; j < Constants::boardEnd + 1; j++)
        {
            auto piece = m_board.GetPieceFromSquare(Square(j, i));
            if (piece == nullptr)
            {
                row += "  ";
            }
            else
            {
                row += " " + PieceToUnicode(piece);
            }
        }
        
        std::cout << row << std::endl;
    }
    
    std::cout << "  A B C D E F G H" << std::endl;
    std::cout << "" << std::endl;
}

std::string BoardPrinter::PieceToUnicode(const std::shared_ptr<Piece>& piece) const
{
    if (piece->color == Color::White)
    {
        switch(piece->pieceType)
        {
            case PieceType::Pawn:
                return "♙";
                break;
            case PieceType::Knight:
                return "♘";
                break;
            case PieceType::Bishop:
                return "♗";
                break;
            case PieceType::Rook:
                return "♖";
                break;
            case PieceType::Queen:
                return "♕";
                break;
            case PieceType::King:
                return "♔";
                break;
        }
    }
    if (piece->color == Color::Black)
    {
        switch(piece->pieceType)
        {
            //ඞ
            case PieceType::Pawn:
                return "♣";
                break;
            case PieceType::Knight:
                return "♞";
                break;
            case PieceType::Bishop:
                return "♝";
                break;
            case PieceType::Rook:
                return "♜";
                break;
            case PieceType::Queen:
                return "♛";
                break;
            case PieceType::King:
                return "♚";
                break;
        }
    }

    return "";
}