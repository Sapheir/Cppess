//
// Created by Turca Vasile
//

#include "ModelUtils.h"

#include <iostream>

bool ModelUtils::inRange(const int  &position, const int &tableSize) {
    if(position <= 0) return false;
    if(position > tableSize) return false;
    return true;
}

bool ModelUtils::insideTable(const int& newPositionX, const int& newPositionY, const int &tableSize){
    if(!inRange(newPositionX, tableSize)) return false;
    if(!inRange(newPositionY, tableSize)) return false;
    return true;
}

std::vector<std::pair<int, int > > ModelUtils::addPositions(const int &scaleX, const int &scaleY, const int &initialX, const int &initialY,
                         const int &tableSize) {
    std::vector < std::pair < int, int > > positions;
    int variation = 1;

    /* compute a new possible position where the piece can go */
    int possiblePositionX = initialX + variation * scaleX;
    int possiblePositionY = initialY + variation * scaleY;
    while(insideTable(possiblePositionX, possiblePositionY, tableSize)){
        positions.emplace_back(possiblePositionX, possiblePositionY);

        /* compute the next set of possible coordinates */
        variation++;

        /* compute a new possible position where the piece can go */
        possiblePositionX = initialX + variation * scaleX;
        possiblePositionY = initialY + variation * scaleY;
    }

    return positions;
}