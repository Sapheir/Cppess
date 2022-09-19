//
// Created by User on 17/09/2022.
//

#include "ModelUtils.h"

std::vector<std::pair<int, int >> ModelUtils::addPositions(const int &scaleX, const int &scaleY, const int &initialX, const int &initialY,
                         const int &tableSize) {
    std::vector < std::pair < int, int >> positions;
    int variation = 1;
    int possiblePositionX;
    int possiblePositionY;
    while(true){
        /* compute a new possible position where the piece can go */
        possiblePositionX = initialX - variation * scaleX;
        possiblePositionY = initialY - variation * scaleY;

        /* we reached the end of the table */
        if(tableSize < possiblePositionX || possiblePositionX <= 0)
            break;

        if(tableSize < possiblePositionY || possiblePositionY <= 0)
            break;
        /* ------------------------------- */

        positions.emplace_back(possiblePositionX, possiblePositionY);

        variation++;
    }

    return positions;
}