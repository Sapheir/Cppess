// Created by Catalin
#include "Game.h"
#include "../model/domain/pieces/rook/Rook.h"
#include "../model/domain/pieces/knight/Knight.h"
#include "../model/domain/pieces/bishop/Bishop.h"
#include "../model/domain/pieces/queen/Queen.h"
#include "../model/domain/pieces/king/King.h"
#include "../model/domain/pieces/pawn/Pawn.h"

Game::Game() {
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

std::vector<std::pair<int, int> > Game::availableMovesDestinations(const int &posX, const int &posY) const {
    return serviceTable.availableMovesDestinations(posX, posY);
}

void Game::checkMoveAvailable(const int &x, const int &y, const int &newX, const int &newY) const {
    return serviceTable.checkMoveAvailable(x, y, newX, newY);
}

