// Created by Catalin
#include "SinglePlayerGame.h"

SinglePlayerGame::SinglePlayerGame(const colors &playerColor)
                : Game{playerColor} {
}

void SinglePlayerGame::movePlayerPiece(const int &x, const int &y, const int &newX, const int &newY) {
    if (isGameOver)
        return;
    auto events = movePiece(x, y, newX, newY);
    for (auto &pieceInfo: currentPiecesInfo) {
        if (pieceInfo.posX == x && pieceInfo.posY == y) {
            pieceInfo.posX = newX;
            pieceInfo.posY = newY;
            break;
        }
    }
    handleMovePieceEvents(events, newX, newY, true);
}

void SinglePlayerGame::moveAIPiece() {
    if (isGameOver)
        return;
    std::cout << "AI move\n";
    for (auto &pieceInfo: currentPiecesInfo) {
        if (pieceInfo.color == getOpponentColor()) {
            auto positions = availableMovesDestinations(pieceInfo.posX, pieceInfo.posY);
            if (!positions.empty()) {
                auto events = movePiece(pieceInfo.posX, pieceInfo.posY, positions[0].first, positions[0].second);
                pieceInfo.posX = positions[0].first;
                pieceInfo.posY = positions[0].second;
                handleMovePieceEvents(events, positions[0].first, positions[0].second, false);
                return;
            }
        }
    }
}
