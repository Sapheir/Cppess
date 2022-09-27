//
// Created by User on 17/09/2022.
//

#include <vector>

#include "../Utils/ModelUtils.h"

#ifndef CPPESS_ROOK_H
#define CPPESS_ROOK_H

class Rook {
private:
    int positionX;
    int positionY;
public:
    Rook(const int &positionX, const int &positionY): positionX{positionX}, positionY{positionY}{};

    /*
     * Return a list of all possible positions inside the chess table where the bishop could be moved
     *
     * @param tableSize: the size of the table
     *
     * @return vector < pair < int, int > > - all possible positions
     */
    [[nodiscard]] std::vector < std::pair < int, int > > nextPositions(const int &tableSize) const;

};

#endif //CPPESS_ROOK_H
