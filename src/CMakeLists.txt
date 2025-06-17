# Set the source files for the main project
set(SRC_FILES
    main.cpp
    Bishop.cpp
    Board.cpp
    CastleChecker.cpp
    CheckChecker.cpp
    DangerChecker.cpp
    King.cpp
    Knight.cpp
    LegalityChecker.cpp
    MoveDialog.cpp
    MoveParser.cpp
    Pawn.cpp
    Piece.cpp
    PieceFactory.cpp
    PositionFunctions.cpp
    Queen.cpp
    Rook.cpp
    )
    
    # Set the header files for the main project
    set(HEADER_FILES
    Bishop.h
    Board.h
    CastleChecker.h
    CheckChecker.h
    Color.h
    DangerChecker.h
    King.h
    Knight.h
    LegalityChecker.h
    Move.h
    MoveDialog.h
    MoveParser.h
    Pawn.h
    Piece.h
    PieceFactory.h
    PositionFunctions.h
    Queen.h
    Rook.h
    Square.h
)

# Add the executable or library
add_library(src STATIC ${SRC_FILES} ${HEADER_FILES})

add_executable(Chess main.cpp)
target_link_libraries(Chess PRIVATE src)