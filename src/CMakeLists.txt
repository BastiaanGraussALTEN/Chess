# Set the source files for the main project
set(SRC_FILES
    main.cpp
    MoveDialog.cpp
    Coord.cpp
    Pawn.cpp
    Piece.cpp
)

# Set the header files for the main project
set(HEADER_FILES
    MoveDialog.h
    Pawn.h
    Piece.h
)

# Add the executable or library
add_library(src STATIC ${SRC_FILES} ${HEADER_FILES})

add_executable(Chess main.cpp)
target_link_libraries(Chess PRIVATE src)