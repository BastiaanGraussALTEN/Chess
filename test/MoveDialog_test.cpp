#include "gtest/gtest.h"
#include "../src/MoveDialog.h"

TEST(additionTest, firstDialog) 
{
    //arrange
    MoveDialog moveDialog;

    //act
    std::string dialog = moveDialog.GetDialog();

    //assert
    EXPECT_EQ (dialog,  "White to move");
}

TEST(additionTest, dialogAfterMove) 
{
    //arrange
    MoveDialog moveDialog;

    //act
    moveDialog.SetMove("move1");

    //assert
    EXPECT_EQ (moveDialog.GetDialog(), "Black to move");
}

TEST(additionTest, dialogAfterTwoMoves) 
{
    //arrange
    MoveDialog moveDialog;

    //act
    moveDialog.SetMove("move1");
    moveDialog.SetMove("move2");

    //assert
    EXPECT_EQ (moveDialog.GetDialog(), "White to move");
}