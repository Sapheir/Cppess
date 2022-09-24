//
// Created by User on 17/09/2022.
//

#include "King.h"

std::vector<std::pair<int, int>> King::nextPositions(const int &tableSize) const {
    std::vector < std::pair < int, int >> allPositions;

    /* we can decrease on x */
    if(position_x > 1){
        /* decrease on y */
        if(position_y > 1)
            allPositions.emplace_back(position_x - 1, position_y - 1);
        /* same position in y */
        allPositions.emplace_back(position_x - 1, position_y);
        /* increase on y */
        if(position_y < tableSize)
            allPositions.emplace_back(position_x - 1, position_y + 1);
    }

    /* we can increase on x */
    if(position_x < tableSize){
        /* decrease on y */
        if(position_y > 1)
            allPositions.emplace_back(position_x + 1, position_y - 1);
        /* same position in y */
        allPositions.emplace_back(position_x + 1, position_y);
        /* increase on y */
        if(position_y < tableSize)
            allPositions.emplace_back(position_x + 1, position_y + 1);
    }

    /* decrease only y */
    if(position_y > 1)
        allPositions.emplace_back(position_x, position_y - 1);
    /* increase only y */
    if(position_y < tableSize)
        allPositions.emplace_back(position_x, position_y + 1);

    return allPositions;

}
