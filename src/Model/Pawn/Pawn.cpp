//
// Created by User on 16/09/2022.
//

#include "Pawn.h"

std::vector<std::pair<int, int>> Pawn::nextPositions(const int &tableSize) const {
    std::vector < std::pair < int, int >> allPositions;
    if(doubleMoveAvailable)
        allPositions.emplace_back(position_x, position_y + 2);
    allPositions.emplace_back(position_x, position_y + 1);
    allPositions.emplace_back(position_x + 1, position_y + 1);
    allPositions.emplace_back(position_x - 1, position_y + 1);

    return allPositions;
}

