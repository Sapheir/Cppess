//
// Created by User on 17/09/2022.
//

#include "Bishop.h"

/*
 * Generate all possible movements from the initial position inside the chess table
 *
 * @param initialX, initialY: initial position of the piece on the chess board
 * @param scaleX: parameters that show if the position on X should increase(1) or decrease(-1)
 * @param scaleY: parameters that show if the position on Y should increase(1) or decrease(-1)
 * @param tableSize: the size of the table
 *
 * @return vector < pair < int, int > > - all generated positions
 */
auto addPositions(const int &scaleX, const int &scaleY,
                  const int &initialX, const int &initialY, int tableSize) {
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
    return allPositions;

}

