// Created by Catalin
#pragma once
#include "../Game.h"
#include "../../gui/components/chess_table/ChessTable.h"

class SinglePlayerGame: public Game {
private:
    colors playerColor;
    bool isGameOver{};

public:
    explicit SinglePlayerGame(const colors &playerColor);

    /**
     * @return Color of the player's pieces
     */
    colors getPlayerColor();

    /**
     * @return Color of the AI's pieces
     */
    colors getAIColor();

    /**
     * @return Whether it's the player's turn or not
     */
    bool isPlayerTurn();

    /**
     * Does a player's input move
     * @param x Initial X coordinate
     * @param y Initial Y coordinate
     * @param newX Destination X coordinate
     * @param newY Destination Y coordinate
     */
    void movePlayerPiece(const int &x, const int &y, const int &newX, const int &newY);

    /**
     * Does the AI's move
     */
    void moveAIPiece();

    /**
     * Handles the events of a piece being moved
     * @param moveEvents Events to handle
     * @param destinationX Destination X coordinate of the move
     * @param destinationY Destination Y coordinate of the move
     * @param isPlayer whether the player or the AI made the move
     */
    void handleMovePieceEvents(std::vector<std::shared_ptr<BaseEvent>> &moveEvents, const int &destinationX, const int &destinationY, const bool &isPlayer);
};
