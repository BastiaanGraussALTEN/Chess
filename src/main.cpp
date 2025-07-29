#include "../header/MoveDialog.h"
#include "../header/MoveParser.h"
#include "../header/CastleChecker.h"
#include "../header/CheckChecker.h"
#include "../header/BoardHistory.h"
#include "../header/BoardPrinter.h"

#include <thread>
#include <atomic>
#include <mutex>

unsigned int squareSize = 80;
unsigned int windowSize = squareSize * 8;
std::atomic<bool> isGameEnded = false;
std::mutex boardMutex;
Board board;
std::mutex moveStringMutex;
std::string moveString;

void terminalInput()
{
    std::cout << "Input thread started\n";
    MoveDialog moveDialog;
    BoardHistory boardHistory;
    while(!isGameEnded)
    {
        boardHistory.AddBoard(board);
        Color colorToMove = moveDialog.GetCurrentTurn();
        MoveParser moveParser(board, colorToMove);
        LegalityChecker legalityChecker = LegalityChecker(board);
        DangerChecker dangerChecker = DangerChecker(board, colorToMove);
        CastleChecker castleChecker = CastleChecker(board, colorToMove);
        CheckChecker checkChecker = CheckChecker(board, colorToMove);

        if (checkChecker.EveryMoveChecksSelf())
        {
            isGameEnded = true;
            moveDialog.ShowMoveHistory();
            if (dangerChecker.IsKingUnderAttack())
            {
                moveDialog.ShowCheckMate();
            }
            else
            {
                moveDialog.ShowStaleMate();
            }
            continue;
        }

        if (board.IsFiftyMoveRule())
        {
            isGameEnded = true;
            moveDialog.ShowMoveHistory();
            moveDialog.Show50MoveDraw();
            continue;
        }

        if (boardHistory.IsThreeFoldRepetition())
        {
            isGameEnded = true;
            moveDialog.ShowMoveHistory();
            moveDialog.ShowThreeFoldRepetition();
            continue;
        }

        if (!checkChecker.SufficientMaterialForCheckmate())
        {
            isGameEnded = true;
            moveDialog.ShowMoveHistory();
            moveDialog.ShowInsufficientMaterial();
            continue;
        }
        
        bool validMoveIsGiven = false;

        while(!validMoveIsGiven)
        {
            moveDialog.ShowMoveHistory();
            moveDialog.ShowDialog();
            std::string inputMove;
            if (!std::getline(std::cin, inputMove))
            {
                isGameEnded = true;
                break;
            }
            {
                std::lock_guard<std::mutex> lock2(moveStringMutex);
                moveString = inputMove;
            }
            Move move = moveParser.ParseString(moveString);
            if (!move.isLegal)
            {
                {
                    std::lock_guard<std::mutex> lock2(moveStringMutex);
                    moveString.clear();
                }
                moveDialog.ShowStringNotValid();
                continue;
            }
            
            if (move.isCastleKingside) 
            {
                if (!castleChecker.CanCastleKingSide())
                {
                    moveDialog.ShowIllegalCastling();
                    continue;
                }

                {
                    std::lock_guard<std::mutex> lock1(boardMutex);
                    board.CastleKingside(colorToMove);
                }
                moveDialog.SetMove(moveString);
                validMoveIsGiven = true;
                continue;
            }
            if (move.isCastleQueenside) 
            {
                if (!castleChecker.CanCastleQueenSide())
                {
                    moveDialog.ShowIllegalCastling();
                    continue;
                }
                
                {
                    std::lock_guard<std::mutex> lock1(boardMutex);
                    board.CastleQueenside(colorToMove);
                }
                moveDialog.SetMove(moveString);
                validMoveIsGiven = true;
                continue;
            }

            if (!legalityChecker.CheckMoveLegality(move))
            {
                moveDialog.ShowMoveNotLegal();
                continue;
            }

            if ((!board.IsThereAPieceOfThisColorHere(colorToMove, move.start))
                && (board.GetPieceFromSquare(move.start) != nullptr))
            {
                moveDialog.ShowPieceWrongColor();
                continue;
            }

            if (!checkChecker.IsKingSafeAfterMove(move))
            {
                moveDialog.ShowMovePutsKingInCheck();
                continue;
            }

            if (legalityChecker.DoesMoveCapturePiece(move))
            {
                std::lock_guard<std::mutex> lock1(boardMutex);
                board.RemovePieceFromSquare(move.end);
                boardHistory.ClearHistory();
            }

            if (board.GetPieceFromSquare(move.start)->pieceType == PieceType::Pawn)
            {
                boardHistory.ClearHistory();
            }

            {
                std::lock_guard<std::mutex> lock1(boardMutex);
                board.MovePiece(move);
            }

            if (move.isPromotion)
            {
                std::lock_guard<std::mutex> lock1(boardMutex);
                board.RemovePieceFromSquare(move.end);
                switch (move.promotionPiece)
                {
                    case PieceType::Knight:
                        board.AddPiece(PieceFactory::CreateKnight(colorToMove, move.end));
                        break;
                    case PieceType::Bishop:
                        board.AddPiece(PieceFactory::CreateBishop(colorToMove, move.end));
                        break;
                    case PieceType::Rook:
                        board.AddPiece(PieceFactory::CreateRook(colorToMove, move.end));
                        break;
                    case PieceType::Queen:
                        board.AddPiece(PieceFactory::CreateQueen(colorToMove, move.end));
                        break;
                }
            }
            moveDialog.SetMove(moveParser.MoveToString(move));
            validMoveIsGiven = true;
            continue;
        }
    }
}

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({windowSize, windowSize}), "Chessboard");
    window.setFramerateLimit(144);
    
    BoardPrinter boardPrinter = BoardPrinter(board, squareSize);
    std::thread inputThread(terminalInput);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        std::string moveToPrint;
        {
            std::lock_guard<std::mutex> lock(moveStringMutex);
            moveToPrint  = moveString;
            moveString.clear();
        }

        if (!moveToPrint.empty()) 
        {
            std::cout << "Processing move: " << moveToPrint  << std::endl;
        }

        {
            window.clear();
            std::lock_guard<std::mutex> lock(boardMutex);
            boardPrinter.DrawEmptyChessBoard(window);
            boardPrinter.DrawPieces(window);
            window.display();
        }
    }

    std::cout << "Window closed" << std::endl;
    inputThread.join();
    return 0;
}