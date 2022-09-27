//
// Created by User on 16/09/2022.
//

#include <vector>

#ifndef CPPESS_PAWN_H
#define CPPESS_PAWN_H

class Pawn {
private:
    int positionX;
    int positionY;

    bool doubleMoveAvailable;
public:
    Pawn(const int &positionX, const int &positionY): positionX{positionX}, positionY{positionY}{
        doubleMoveAvailable = true;
    };

    /*
     * Return a list of all possible positions inside the chess table where the bishop could be moved
     *
     * @param tableSize: the size of the table
     *
     * @return vector < pair < int, int > > - all possible positions
     */
    [[nodiscard]] std::vector < std::pair < int, int > > nextPositions(const int &tableSize) const;

};

#endif //CPPESS_PAWN_H
