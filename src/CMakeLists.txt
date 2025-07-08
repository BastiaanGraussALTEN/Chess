# Set the source files for the main project
set(SRC_FILES
    sourcefiles/main.cpp
    sourcefiles/Bishop.cpp
    sourcefiles/Board.cpp
    sourcefiles/CastleChecker.cpp
    sourcefiles/CheckChecker.cpp
    sourcefiles/DangerChecker.cpp
    sourcefiles/King.cpp
    sourcefiles/Knight.cpp
    sourcefiles/LegalityChecker.cpp
    sourcefiles/MoveDialog.cpp
    sourcefiles/MoveParser.cpp
    sourcefiles/Pawn.cpp
    sourcefiles/Piece.cpp
    sourcefiles/PieceFactory.cpp
    sourcefiles/PositionFunctions.cpp
    sourcefiles/Queen.cpp
    sourcefiles/Rook.cpp
    )
    
# Set the header files for the main project
set(HEADER_FILES
    headerfiles/Bishop.h
    headerfiles/Board.h
    headerfiles/CastleChecker.h
    headerfiles/CheckChecker.h
    headerfiles/Color.h
    headerfiles/Constants.h
    headerfiles/DangerChecker.h
    headerfiles/King.h
    headerfiles/Knight.h
    headerfiles/LegalityChecker.h
    headerfiles/Move.h
    headerfiles/MoveDialog.h
    headerfiles/MoveParser.h
    headerfiles/Pawn.h
    headerfiles/Piece.h
    headerfiles/PieceFactory.h
    headerfiles/PositionFunctions.h
    headerfiles/Queen.h
    headerfiles/Rook.h
    headerfiles/Square.h
    headerfiles/TestFunctions.h
)

# Add the executable or library
add_library(src STATIC ${SRC_FILES} ${HEADER_FILES})

add_executable(Chess sourcefiles/main.cpp)
target_link_libraries(Chess PRIVATE src)