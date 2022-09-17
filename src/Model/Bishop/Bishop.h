//
// Created by User on 17/09/2022.
//

#include <vector>
#include "../Utils/ModelUtils.h"

#ifndef CPPESS_BISHOP_H
#define CPPESS_BISHOP_H

class Bishop {
private:
    int position_x;
    int position_y;
public:
    Bishop(const int &position_x, const int &position_y): position_x{position_x}, position_y{position_y}{};

    /*
     * Return a list of all possible positions inside the chess table where the bishop could be moved
     *
     * @param tableSize: the size of the table
     *
     * @return vector < pair < int, int > > - all possible positions
     */
    [[nodiscard]] std::vector<std::pair<int, int>> nextPositions(int tableSize) const;

};

#endif //CPPESS_BISHOP_H
