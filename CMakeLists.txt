cmake_minimum_required(VERSION 3.14)
project(Chess)

# C++ standard
set(CMAKE_CXX_STANDARD 17)

# Enable testing
enable_testing()

# Add src and test directories
add_subdirectory(src)
add_subdirectory(external/googletest)
add_subdirectory(external/SFML)
add_subdirectory(test)

add_executable(Chess src/main.cpp)
target_link_libraries(Chess PRIVATE src)