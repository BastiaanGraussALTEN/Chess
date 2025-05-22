cmake_minimum_required(VERSION 3.14)
project(Chess)

# C++ standard
set(CMAKE_CXX_STANDARD 17)

add_executable(Chess src/main.cpp)

# Enable testing
enable_testing()

# Add src and test directories
add_subdirectory(src)
add_subdirectory(external/googletest-1.17.0)
add_subdirectory(test)