#include "gtest/gtest.h"
#include "../src/MoveParser.h"

TEST(MoveParserTest, invalidStringGivesInvalidMove)
{
    // Arrange
    MoveParser moveParser;
    std::string moveString = "e2e4";
    Move expectedMove = Move(Square(5,2),Square(5,4));

    // Act
    Move actualMove = moveParser.ParseString(moveString);

    // Assert
    EXPECT_EQ(actualMove, expectedMove);
}