//
// Created by User on 17/09/2022.
//

#include "Knight.h"

bool inTableRange(const int  &position, const int &tableSize){
    if(position <= 0) return false;
    if(position > tableSize) return false;
    return true;
}

bool insideTable(const int& newPositionX, const int& newPositionY, const int &tableSize){
    if(!inTableRange(newPositionX, tableSize)) return false;
    if(!inTableRange(newPositionY, tableSize)) return false;
    return true;
}

std::vector<std::pair<int, int>> Knight::nextPositions(const int &tableSize) const {
    std::vector < std::pair < int, int >> allPositions;

    const int variationX[] = {-2, -2, -1, -1, 2,  2,  1,  1};
    const int variationY[] = {-1, 1,  -2, 2,  -1, 1,  -2, 2};
    int numberOfVariations = 8;

    for(int iterator = 0 ; iterator <= numberOfVariations ; iterator++){
        int newPositionX = position_x + variationX[iterator];
        int newPositionY = position_y + variationY[iterator];

        if(insideTable(newPositionX, newPositionY, tableSize))
            allPositions.emplace_back(newPositionX, newPositionY);
    }

    return allPositions;

}

