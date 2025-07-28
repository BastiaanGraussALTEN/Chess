# Set the source files for the main project
set(SRC_FILES
    main.cpp
    Bishop.cpp
    Board.cpp
    BoardHistory.cpp
    BoardPrinter.cpp
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
    ../header/Bishop.h
    ../header/Board.h
    ../header/BoardHistory.h
    ../header/BoardPrinter.h
    ../header/CastleChecker.h
    ../header/CheckChecker.h
    ../header/Color.h
    ../header/Constants.h
    ../header/DangerChecker.h
    ../header/King.h
    ../header/Knight.h
    ../header/LegalityChecker.h
    ../header/Move.h
    ../header/MoveDialog.h
    ../header/MoveParser.h
    ../header/Pawn.h
    ../header/Piece.h
    ../header/PieceFactory.h
    ../header/PositionFunctions.h
    ../header/Queen.h
    ../header/Rook.h
    ../header/Square.h
    ../header/TestFunctions.h
)

add_library(src STATIC ${SRC_FILES} ${HEADER_FILES})

target_link_libraries(src PUBLIC sfml-graphics sfml-window sfml-system)