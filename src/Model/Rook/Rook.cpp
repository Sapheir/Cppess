//
// Created by User on 17/09/2022.
//

#include "Rook.h"

std::vector<std::pair<int, int>> Rook::nextPositions(const int &tableSize) const {
    std::vector < std::pair < int, int >> allPositions;

    const int scalesOnX[] = {-1, 1, 0,  0};
    const int scalesOnY[] = {0,  0, -1, 1};

    /* add all possible positions straight on horizontally or vertically*/
    for(int index = 0 ; index < 4 ; index++){
        std::vector < std::pair < int, int >> generatedPositions = ModelUtils::addPositions(scalesOnX[index], scalesOnY[index], position_x, position_y, tableSize);
        allPositions.insert(allPositions.end(), generatedPositions.begin(), generatedPositions.end());
    }

    return allPositions;
}
