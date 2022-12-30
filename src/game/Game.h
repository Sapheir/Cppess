// Created by Catalin
#pragma once
#include "../model/services/ServiceTable.h"
#include "../model/domain/pieces/pieces.h"

class Game {
private:
    ServiceTable serviceTable;
    std::vector<piece_info> currentPiecesInfo;

    void addInitialPieces();

public:
    Game();

    std::vector<piece_info> getCurrentPiecesInfo();
    [[nodiscard]] std::vector < std::pair < int, int > > availableMovesDestinations(const int &posX, const int &posY) const;
    void checkMoveAvailable(const int &x, const int &y, const int &newX, const int &newY) const;
};
