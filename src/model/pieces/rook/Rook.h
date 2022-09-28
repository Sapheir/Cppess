//
// Created by Turca Vasile
//

#include <vector>

#include "../utils/ModelUtils.h"
#include "../Piece.h"

#ifndef CPPESS_ROOK_H
#define CPPESS_ROOK_H

class Rook: public Piece {
private:

public:
    Rook(const int &positionX, const int &positionY):Piece{positionX, positionY}{};

    /*
     * Return a list of all possible positions inside the chess table where the bishop could be moved
     *
     * @param tableSize: the size of the table
     *
     * @return vector < pair < int, int > > - all possible positions
     */
    [[nodiscard]] std::vector < std::pair < int, int > > nextPositions(const int &tableSize) const override;

};

#endif //CPPESS_ROOK_H
