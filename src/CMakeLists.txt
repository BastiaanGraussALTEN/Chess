# Set the source files for the main project
set(SRC_FILES
    main.cpp
    Bishop.cpp
    Board.cpp
    MoveDialog.cpp
    King.cpp
    Knight.cpp
    LegalityChecker.cpp
    Pawn.cpp
    Piece.cpp
    PieceFactory.cpp
    Queen.cpp
    Rook.cpp
    )
    
    # Set the header files for the main project
    set(HEADER_FILES
    Bishop.h
    Board.h
    Color.h
    Move.h
    MoveDialog.h
    King.h
    Knight.h
    LegalityChecker.h
    Pawn.h
    Piece.h
    PieceFactory.h
    Queen.h
    Rook.h
    Square.h
)

# Add the executable or library
add_library(src STATIC ${SRC_FILES} ${HEADER_FILES})

add_executable(Chess main.cpp)
target_link_libraries(Chess PRIVATE src)