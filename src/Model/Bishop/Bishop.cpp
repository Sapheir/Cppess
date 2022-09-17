//
// Created by User on 17/09/2022.
//

#include "Bishop.h"

std::vector<std::pair<int, int>> Bishop::nextPositions(int tableSize) const {
    std::vector < std::pair < int, int >> allPositions;

    const int scales[] = {-1, 1};

    /* add all possible positions straight on horizontally or vertically or diagonally */
    for(int indexScaleX = 0 ; indexScaleX < 3 ; indexScaleX++)
        for(int indexScaleY = 0 ; indexScaleY < 3 ; indexScaleY++) {
            auto generatedPositions = addPositions(scales[indexScaleX], scales[indexScaleY], position_x, position_y, tableSize);
            allPositions.insert(allPositions.end(), generatedPositions.begin(), generatedPositions.end());
        }

    return allPositions;
}

