#include "gtest/gtest.h"
#include "../src/addition.h"

TEST(additionTest, test1) 
{
    //arrange
    //act
    //assert
    EXPECT_EQ (add(2, 4),  6);
}

TEST(additionTest, test2) 
{
    //arrange
    //act
    //assert
    EXPECT_NE (add(2, 3),  6);
}