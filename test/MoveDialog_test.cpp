#include "gtest/gtest.h"
#include "../src/MoveDialog.h"

// TEST(MoveDialogTest, firstDialog) 
// {
//     // Arrange
//     MoveDialog moveDialog;

//     // Act
//     std::string dialog = moveDialog.GetSingleLineDialog();

//     // Assert
//     EXPECT_EQ(dialog,  "White to move, insert your Move: ");
// }

// TEST(MoveDialogTest, dialogAfterMove) 
// {
//     // Arrange
//     MoveDialog moveDialog;

//     // Act
//     moveDialog.SetMove("move1");

//     // Assert
//     EXPECT_EQ(moveDialog.GetSingleLineDialog(), "Black to move, insert your Move: ");
// }

// TEST(MoveDialogTest, dialogAfterTwoMoves) 
// {
//     // Arrange
//     MoveDialog moveDialog;

//     // Act
//     moveDialog.SetMove("move1");
//     moveDialog.SetMove("move2");

//     // Assert
//     EXPECT_EQ(moveDialog.GetSingleLineDialog(), "White to move, insert your Move: ");
// }

// TEST(MoveDialogTest, showingDialogHistory)
// {
//     // Arrange
//     MoveDialog moveDialog;
//     moveDialog.SetMove("move1");
//     moveDialog.SetMove("move2");
//     moveDialog.SetMove("move3");
//     moveDialog.SetMove("move4");
    
//     // Act
//     std::string expectedMoveHistory = "\nMove history:\nmove1\tmove2\nmove3\tmove4\n\n";

//     // Assert
//     EXPECT_EQ(moveDialog.GetMoveHistory(), expectedMoveHistory);
// }