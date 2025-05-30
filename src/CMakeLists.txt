# Set the source files for the main project
set(SRC_FILES
    main.cpp
    Bishop.cpp
    MoveDialog.cpp
    Coord.cpp
    King.cpp
    Knight.cpp
    Pawn.cpp
    Piece.cpp
    PieceFactory.cpp
    Queen.cpp
    Rook.cpp
)

# Set the header files for the main project
set(HEADER_FILES
    Bishop.h
    MoveDialog.h
    King.h
    Knight.h
    Pawn.h
    Piece.h
    PieceFactory.h
    Queen.h
    Rook.h
)

# Add the executable or library
add_library(src STATIC ${SRC_FILES} ${HEADER_FILES})

add_executable(Chess main.cpp)
target_link_libraries(Chess PRIVATE src)