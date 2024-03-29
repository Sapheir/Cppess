// Created by Catalin
#include "Game.h"
#include "../model/domain/pieces/rook/Rook.h"
#include "../model/domain/pieces/knight/Knight.h"
#include "../model/domain/pieces/bishop/Bishop.h"
#include "../model/domain/pieces/queen/Queen.h"
#include "../model/domain/pieces/king/King.h"
#include "../model/domain/pieces/pawn/Pawn.h"

Game::Game(const colors &myColor): myColor{myColor} {
    std::unique_ptr<Table> table = std::make_unique<Table>(8);
    serviceTable = ServiceTable{table, white, black};
    addInitialPieces();
}

void Game::addInitialPieces() {
    // Add white pieces
    serviceTable.addPiece(std::make_shared<Rook>(0, 7, white));
    currentPiecesInfo.push_back({rook, 0, 7, white});
    serviceTable.addPiece(std::make_shared<Knight>(1, 7, white));
    currentPiecesInfo.push_back({knight, 1, 7, white});
    serviceTable.addPiece(std::make_shared<Bishop>(2, 7, white));
    currentPiecesInfo.push_back({bishop, 2, 7, white});
    serviceTable.addPiece(std::make_shared<Queen>(3, 7, white));
    currentPiecesInfo.push_back({queen, 3, 7, white});
    serviceTable.addPiece(std::make_shared<King>(4, 7, white));
    currentPiecesInfo.push_back({king, 4, 7, white});
    serviceTable.addPiece(std::make_shared<Bishop>(5, 7, white));
    currentPiecesInfo.push_back({bishop, 5, 7, white});
    serviceTable.addPiece(std::make_shared<Knight>(6, 7, white));
    currentPiecesInfo.push_back({knight, 6, 7, white});
    serviceTable.addPiece(std::make_shared<Rook>(7, 7, white));
    currentPiecesInfo.push_back({rook, 7, 7, white});
    for (int i = 0; i<8; i++) {
        serviceTable.addPiece(std::make_shared<Pawn>(i, 6, white));
        currentPiecesInfo.push_back({pawn, i, 6, white});
    }

    // Add black pieces
    serviceTable.addPiece(std::make_shared<Rook>(0, 0, black));
    currentPiecesInfo.push_back({rook, 0, 0, black});
    serviceTable.addPiece(std::make_shared<Knight>(1, 0, black));
    currentPiecesInfo.push_back({knight, 1, 0, black});
    serviceTable.addPiece(std::make_shared<Bishop>(2, 0, black));
    currentPiecesInfo.push_back({bishop, 2, 0, black});
    serviceTable.addPiece(std::make_shared<Queen>(3, 0, black));
    currentPiecesInfo.push_back({queen, 3, 0, black});
    serviceTable.addPiece(std::make_shared<King>(4, 0, black));
    currentPiecesInfo.push_back({king, 4, 0, black});
    serviceTable.addPiece(std::make_shared<Bishop>(5, 0, black));
    currentPiecesInfo.push_back({bishop, 5, 0, black});
    serviceTable.addPiece(std::make_shared<Knight>(6, 0, black));
    currentPiecesInfo.push_back({knight, 6, 0, black});
    serviceTable.addPiece(std::make_shared<Rook>(7, 0, black));
    currentPiecesInfo.push_back({rook, 7, 0, black});
    for (int i = 0; i<8; i++) {
        serviceTable.addPiece(std::make_shared<Pawn>(i, 1, black));
        currentPiecesInfo.push_back({pawn, i, 1, black});
    }
}

std::vector<piece_info> Game::getCurrentPiecesInfo() {
    return currentPiecesInfo;
}

std::vector<std::pair<int, int> > Game::availableMovesDestinations(const int &posX, const int &posY) {
    return serviceTable.availableMovesDestinations(posX, posY);
}

std::vector<std::shared_ptr<BaseEvent> > Game::movePiece(const int &x, const int &y, const int &newX, const int &newY) {
    return serviceTable.movePiece(x, y, newX, newY);
}

void Game::removePieceVisually(const int &posX, const int &posY, const colors &pieceColor) {
    currentPiecesInfo.erase(std::remove_if(currentPiecesInfo.begin(), currentPiecesInfo.end(),
                                           [posX, posY, pieceColor](const piece_info &pieceInfo){
                                                return pieceInfo.posX == posX && pieceInfo.posY == posY && pieceInfo.color == pieceColor;
                                            }), currentPiecesInfo.end());
}

void Game::movePieceVisually(const piece_types &pieceType, const int &posX, const int &posY, const colors &pieceColor, const int &newPosX, const int &newPosY) {
    std::replace_if(currentPiecesInfo.begin(), currentPiecesInfo.end(),
                       [pieceType, posX, posY, pieceColor](const piece_info &pieceInfo){
                           return pieceInfo.posX == posX && pieceInfo.posY == posY && pieceInfo.color == pieceColor && pieceInfo.piece_type == pieceType;
                       }, piece_info{pieceType, newPosX, newPosY, pieceColor});
}

colors Game::getMyColor() {
    return myColor;
}

colors Game::getOpponentColor() {
    return myColor == white ? black : white;
}

bool Game::isMyTurn() {
    return serviceTable.getCurrentPlayer() == getMyColor();
}

void Game::handleMovePieceEvents(std::vector<std::shared_ptr<BaseEvent>> &moveEvents,
                                 const int &destinationX, const int &destinationY, const bool &isMe) {
    auto color = isMe ? getOpponentColor() : getMyColor(), otherColor = !isMe ? getOpponentColor() : getMyColor();
    std::cout << "Events: ";
    for (const auto &event: moveEvents) {
        std::cout << event->getEventType() << " ";
        switch (event->getEventType()) {
            case capture:
                removePieceVisually(destinationX, destinationY, color);
                break;
            case castling: {
                auto [kingAfterX, kingAfterY] = event->getKingPosAfterCastle();
                auto [rookBeforeX, rookBeforeY] = event->getRookPosBeforeCastle();
                auto [rookAfterX, rookAfterY] = event->getRookPosAfterCastle();
                movePieceVisually(king, rookBeforeX, rookBeforeY, otherColor, kingAfterX, kingAfterY);
                movePieceVisually(rook, rookBeforeX, rookBeforeY, otherColor, rookAfterX, rookAfterY);
                break;
            }
            case king_under_attack:
                break;
            case win:
                isGameOver = true;
                break;
            default:
                std::cout << event->getEventType() << " not implemented\n";
                break;
        }
    }
    std::cout << ";\n";
}
