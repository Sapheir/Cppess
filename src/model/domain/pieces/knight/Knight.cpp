//
// Created by Turca Vasile
//

#include "Knight.h"

std::vector<std::pair<int, int> > Knight::nextPositions(const int &tableSize) const {
    std::vector < std::pair < int, int > > allPositions;

    const int variationX[] = {-2, -2, -1, -1, 2,  2,  1,  1};
    const int variationY[] = {-1, 1,  -2, 2,  -1, 1,  -2, 2};
    int numberOfVariations = 8;

    for(int iterator = 0 ; iterator < numberOfVariations ; iterator++){
        int newPositionX = positionX + variationX[iterator];
        int newPositionY = positionY + variationY[iterator];

        if(insideSquareTable(newPositionX, newPositionY, tableSize))
            allPositions.emplace_back(newPositionX, newPositionY);
    }

    return allPositions;

}

bool Knight::isKnight() const {
    return true;
}

bool Knight::isPawn() const {
    return false;
}

bool Knight::isKing() const {
    return false;
}

