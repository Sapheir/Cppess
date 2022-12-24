//
// Created by Turca Vasile
//

#include <iostream>
#include "Pawn.h"

std::vector<std::pair<int, int> > Pawn::nextPositions(const int &tableSize) const {
    std::vector < std::pair < int, int > > allPositions;
    if(this->getColor() == black) {
        if (doubleMoveAvailable && positionY + 2 <= tableSize)
            allPositions.emplace_back(positionX, positionY + 2);
        if (positionY < tableSize)
            allPositions.emplace_back(positionX, positionY + 1);
        if (positionX < tableSize && positionY < tableSize)
            allPositions.emplace_back(positionX + 1, positionY + 1);
        if (positionX > 1 && positionY < tableSize)
            allPositions.emplace_back(positionX - 1, positionY + 1);
        return allPositions;
    }
    if(this->getColor() == white){
        if (doubleMoveAvailable && positionY - 2 >= 1)
            allPositions.emplace_back(positionX, positionY - 2);
        if (positionY > 1)
            allPositions.emplace_back(positionX, positionY - 1);
        if (positionX < tableSize && positionY > 1)
            allPositions.emplace_back(positionX + 1, positionY - 1);
        if (positionX > 1 && positionY > 1)
            allPositions.emplace_back(positionX - 1, positionY - 1);
        return allPositions;
    }

}

bool Pawn::isKnight() const {
    return false;
}

bool Pawn::isPawn() const {
    return true;
}

