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

void SinglePlayerGame::moveOpponentPiece(const int &x, const int &y, const int &newX, const int &newY) {
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
    handleMovePieceEvents(events, newX, newY, false);
}
