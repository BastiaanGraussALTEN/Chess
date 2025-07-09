#include "gtest/gtest.h"
#include "../header/MoveDialog.h"

TEST(MoveDialogTest, firstDialog) 
{
    // Arrange
    MoveDialog moveDialog;
    std::stringstream buffer;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    // Act
    moveDialog.ShowDialog();
    std::cout.rdbuf(oldCoutStreamBuf);
    std::string output = buffer.str();

    // Assert
    EXPECT_EQ(output,  "White to move, insert your Move: \n");
    EXPECT_EQ(moveDialog.GetCurrentTurn(), Color::White);
}

TEST(MoveDialogTest, dialogAfterMove) 
{
    // Arrange
    MoveDialog moveDialog;
    std::stringstream buffer;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    moveDialog.SetMove("White1");

    // Act
    moveDialog.ShowDialog();
    std::cout.rdbuf(oldCoutStreamBuf);
    std::string output = buffer.str();

    // Assert
    EXPECT_EQ(output,  "\nMove history:\n1. White1\n\nBlack to move, insert your Move: \n");
    EXPECT_EQ(moveDialog.GetCurrentTurn(), Color::Black);
}

TEST(MoveDialogTest, dialogAfterThreeMoves) 
{
    // Arrange
    MoveDialog moveDialog;
    std::stringstream buffer;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    moveDialog.SetMove("White1");
    moveDialog.SetMove("Black1");
    moveDialog.SetMove("White2");

    // Act
    moveDialog.ShowDialog();
    std::cout.rdbuf(oldCoutStreamBuf);
    std::string output = buffer.str();

    // Assert
    EXPECT_EQ(output,  "\nMove history:\n1. White1 Black1\n2. White2\n\nBlack to move, insert your Move: \n");
}