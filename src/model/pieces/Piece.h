//
// Created by User on 27/09/2022.
//

#include <vector>

#ifndef CPPESS_PIECE_H
#define CPPESS_PIECE_H

class Piece{
private:
    
public:
    /*
     * Return a list of all possible positions inside the chess table where the bishop could be moved
     *
     * @param tableSize: the size of the table
     *
     * @return vector < pair < int, int > > - all possible positions
     */
    [[nodiscard]] virtual std::vector < std::pair < int, int > > nextPositions(const int &tableSize) const = 0;

};

#endif //CPPESS_PIECE_H
