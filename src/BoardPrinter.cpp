#include "../header/BoardPrinter.h"
#include "../header/Constants.h"

#include <iostream>

BoardPrinter::BoardPrinter(const Board& board) : m_board(board)
{
}

void BoardPrinter::PrintEmptyBoard() const
{
    std::cout << "8 ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜" << std::endl;
    std::cout << "7 ඞ ඞ ඞ ඞ ඞ ඞ ඞ ඞ" << std::endl;
    std::cout << "6                " << std::endl;
    std::cout << "5                " << std::endl;
    std::cout << "4                " << std::endl;
    std::cout << "3                " << std::endl;
    std::cout << "2 ♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙" << std::endl;
    std::cout << "1 ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖" << std::endl;
    std::cout << " A B C D E F G H" << std::endl;
}

void BoardPrinter::PrintBoard() const
{
    for(int i = 0; i < Constants::boardEnd; i++)
    {

    }
}

// std::cout << "♚ ♛ ♜ ♝ ♞ ඞ" << std::endl;
// std::cout << "♔ ♕ ♖ ♗ ♘ ♙" << std::endl;