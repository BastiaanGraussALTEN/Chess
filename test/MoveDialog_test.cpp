#include "gtest/gtest.h"
#include "../src/MoveDialog.h"

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
    EXPECT_EQ(output,  "\nMove history:\n\n\nWhite to move, insert your Move: ");
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
    EXPECT_EQ(output,  "\nMove history:\nWhite1\t\n\nBlack to move, insert your Move: ");
}

TEST(MoveDialogTest, dialogAfterTwoMoves) 
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
    EXPECT_EQ(output,  "\nMove history:\nWhite1\tBlack1\nWhite2\t\n\nBlack to move, insert your Move: ");
}