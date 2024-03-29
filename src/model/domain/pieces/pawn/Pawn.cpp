//
// Created by Turca Vasile
//

#include <iostream>
#include "Pawn.h"

std::vector<std::pair<int, int> > Pawn::nextPositions(const int &tableSize) const {
    std::vector < std::pair < int, int > > allPositions;
    if(this->getColor() == black) {
        if (doubleMoveAvailable && positionY + 2 < tableSize - 1)
            allPositions.emplace_back(positionX, positionY + 2);
        if (positionY < tableSize - 1)
            allPositions.emplace_back(positionX, positionY + 1);
        if (positionX < tableSize - 1 && positionY + 1 < tableSize - 1)
            allPositions.emplace_back(positionX + 1, positionY + 1);
        if (positionX >= 1 && positionY + 1 < tableSize - 1)
            allPositions.emplace_back(positionX - 1, positionY + 1);
        return allPositions;
    }
    if(this->getColor() == white){
        if (doubleMoveAvailable && positionY - 2 >= 1)
            allPositions.emplace_back(positionX, positionY - 2);
        if (positionY >= 1)
            allPositions.emplace_back(positionX, positionY - 1);
        if (positionX < tableSize - 1 && positionY >= 1)
            allPositions.emplace_back(positionX + 1, positionY - 1);
        if (positionX >= 1 && positionY >= 1)
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

bool Pawn::isKing() const {
    return false;
}

void Pawn::doubleMoveDisable() {
    this->doubleMoveAvailable = false;
}

bool Pawn::isRook() const {
    return false;
}

