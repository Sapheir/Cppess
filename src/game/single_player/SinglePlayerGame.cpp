// Created by Catalin
#include "SinglePlayerGame.h"

SinglePlayerGame::SinglePlayerGame(const colors &playerColor)
                : Game{}, playerColor{playerColor} {
}

colors SinglePlayerGame::getPlayerColor() {
    return playerColor;
}

colors SinglePlayerGame::getAIColor() {
    return playerColor == white ? black : white;
}

bool SinglePlayerGame::isPlayerTurn() {
    return serviceTable.getCurrentPlayer() == playerColor;
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
        if (pieceInfo.color == getAIColor()) {
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

void SinglePlayerGame::handleMovePieceEvents(std::vector<std::shared_ptr<BaseEvent>> &moveEvents, const int &destinationX, const int &destinationY, const bool &isPlayer) {
    for (const auto &event: moveEvents) {
        switch (event->getEventType()) {
            case capture:
                removePiece(destinationX, destinationY, isPlayer ? getAIColor() : getPlayerColor());
                break;
            case king_under_attack:
                if (!isPlayer)
                    std::cout << "The player's king is under check!\n";
                else
                    std::cout << "The AI's king is under check!\n";
                break;
            case win:
                if (isPlayer)
                    std::cout << "The player won!\n";
                else
                    std::cout << "The AI won!\n";
                isGameOver = true;
                break;
            default:
                std::cout << event->getEventType() << " not implemented\n";
                break;
        }
    }
}
