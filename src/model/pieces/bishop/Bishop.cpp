//
// Created by Turca Vasile
//

#include "Bishop.h"

std::vector<std::pair<int, int> > Bishop::nextPositions(const int &tableSize) const {
    std::vector < std::pair < int, int > > allPositions;

    const int scales[] = {-1, 1};

    /* add all possible positions straight on horizontally or vertically or diagonally */
    for(int indexScaleX = 0 ; indexScaleX < 2 ; indexScaleX++)
        for(int indexScaleY = 0 ; indexScaleY < 2 ; indexScaleY++) {
            std::vector < std::pair < int, int > > generatedPositions = ModelUtils::addPositions(scales[indexScaleX], scales[indexScaleY], positionX, positionY, tableSize);
            allPositions.insert(allPositions.end(), generatedPositions.begin(), generatedPositions.end());
        }

    return allPositions;
}

