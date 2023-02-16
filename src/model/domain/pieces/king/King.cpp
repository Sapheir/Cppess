//
// Created by Turca Vasile
//

#include "King.h"

std::vector<std::pair<int, int> > King::nextPositions(const int &tableSize) const {
    std::vector < std::pair < int, int > > allPositions;

    /* we can decrease on x */
    if(positionX >= 1){
        /* decrease on y */
        if(positionY >= 1)
            allPositions.emplace_back(positionX - 1, positionY - 1);
        /* same position in y */
        allPositions.emplace_back(positionX - 1, positionY);
        /* increase on y */
        if(positionY < tableSize)
            allPositions.emplace_back(positionX - 1, positionY + 1);
    }

    /* we can increase on x */
    if(positionX < tableSize){
        /* decrease on y */
        if(positionY >= 1)
            allPositions.emplace_back(positionX + 1, positionY - 1);
        /* same position in y */
        allPositions.emplace_back(positionX + 1, positionY);
        /* increase on y */
        if(positionY < tableSize)
            allPositions.emplace_back(positionX + 1, positionY + 1);
    }

    /* decrease only y */
    if(positionY > 1)
        allPositions.emplace_back(positionX, positionY - 1);
    /* increase only y */
    if(positionY < tableSize)
        allPositions.emplace_back(positionX, positionY + 1);

    return allPositions;

}

bool King::isKnight() const {
    return false;
}

bool King::isPawn() const {
    return false;
}

bool King::isKing() const {
    return true;
}

bool King::isRook() const {
    return false;
}
