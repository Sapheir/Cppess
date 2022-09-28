//
// Created by Turca Vasile
//
#include "../Piece.h"
#include <vector>

#ifndef CPPESS_PAWN_H
#define CPPESS_PAWN_H

class Pawn: public Piece {
private:
    bool doubleMoveAvailable;
public:
    Pawn(const int &positionX, const int &positionY): Piece{positionX, positionY}{
        doubleMoveAvailable = true;
    };

    /*
     * Return a list of all possible positions inside the chess table where the bishop could be moved
     *
     * @param tableSize: the size of the table
     *
     * @return vector < pair < int, int > > - all possible positions
     */
    [[nodiscard]] std::vector < std::pair < int, int > > nextPositions(const int &tableSize) const override;

};

#endif //CPPESS_PAWN_H
