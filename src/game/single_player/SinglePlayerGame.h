// Created by Catalin
#pragma once
#include "../Game.h"
#include "../../gui/components/chess_table/ChessTable.h"

class SinglePlayerGame: public Game {
public:
    explicit SinglePlayerGame(const colors &playerColor);

    /**
     * Does a player's input move
     * @param x Initial X coordinate
     * @param y Initial Y coordinate
     * @param newX Destination X coordinate
     * @param newY Destination Y coordinate
     */
    void movePlayerPiece(const int &x, const int &y, const int &newX, const int &newY);

    /**
     * Does the opponent's input move
     * @param x Initial X coordinate
     * @param y Initial Y coordinate
     * @param newX Destination X coordinate
     * @param newY Destination Y coordinate
     */
    void moveOpponentPiece(const int &x, const int &y, const int &newX, const int &newY);
};
