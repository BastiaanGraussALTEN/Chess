#include "gtest/gtest.h"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    // ::testing::GTEST_FLAG(filter) = "CastleCheckerTest*";
    return RUN_ALL_TESTS();
}