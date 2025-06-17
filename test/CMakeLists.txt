# Add test source
add_executable(my_tests
    test_main.cpp
    # Board_test.cpp
    # CastleChecker_test.cpp
    CheckChecker_test.cpp
    # DangerChecker_test.cpp
    # LegalityChecker_test.cpp
    # MoveDialog_test.cpp
    # Piece_test.cpp
    # Square_test.cpp
)

# Link with GTest
target_link_libraries(my_tests
    gtest_main
    src
)

# Enable CTest
enable_testing()

# Discover and register tests
include(GoogleTest)
gtest_discover_tests(my_tests)