// Created by Catalin
#pragma once
#include "../model/services/ServiceTable.h"
#include "../model/domain/pieces/pieces.h"

class Game {
protected:
    ServiceTable serviceTable;
    std::vector<piece_info> currentPiecesInfo;

    void addInitialPieces();
    std::vector < std::shared_ptr < BaseEvent > > movePiece(const int &x, const int &y, const int &newX, const int &newY);

public:
    Game();

    /**
     * @return Information about the pieces which are currently in play in the game
     */
    std::vector<piece_info> getCurrentPiecesInfo();

    /**
     * Gets all possible destinations for a piece
     * @param posX X coordinate of the piece checked
     * @param posY Y coordinate of the piece checked
     * @return List of all available destinations for the piece
     */
    [[nodiscard]] std::vector < std::pair < int, int > > availableMovesDestinations(const int &posX, const int &posY);

    /**
     * Removes a piece from the game
     * @param posX X coordinate of the piece to remove
     * @param posY Y coordinate of the piece to remove
     * @param pieceColor color of the piece to remove
     */
    void removePiece(const int &posX, const int &posY, const colors &pieceColor);
};
