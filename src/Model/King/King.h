//
// Created by User on 17/09/2022.
//

#include <vector>

#ifndef CPPESS_KING_H
#define CPPESS_KING_H

class King {
private:
    int position_x;
    int position_y;
public:
    King(const int &position_x, const int &position_y): position_x{position_x}, position_y{position_y}{};

    std::vector < std::pair < int, int > > nextPositions(int tableSize) const;

};

#endif //CPPESS_KING_H
