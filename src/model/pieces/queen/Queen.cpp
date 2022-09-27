//
// Created by User on 17/09/2022.
//

#include "Queen.h"

std::vector<std::pair<int, int>> Queen::nextPositions(const int &tableSize) const {
    std::vector < std::pair < int, int >> allPositions;

    const int scales[] = {-1, 0, 1};

    /* add all possible positions straight on horizontally or vertically or diagonally */
    for(int indexScaleX = 0 ; indexScaleX < 3 ; indexScaleX++)
        for(int indexScaleY = 0 ; indexScaleY < 3 ; indexScaleY++) {
            if(scales[indexScaleX] == 0 && indexScaleX == indexScaleY)
                continue; /* it would lead to movement to the same position */
            std::vector < std::pair < int, int >>generatedPositions =  ModelUtils::addPositions(scales[indexScaleX], scales[indexScaleY], positionX, positionY, tableSize);
            allPositions.insert(allPositions.end(), generatedPositions.begin(), generatedPositions.end());
        }

   return allPositions;

}

