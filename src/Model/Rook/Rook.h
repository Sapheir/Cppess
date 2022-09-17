//
// Created by User on 17/09/2022.
//

#include <vector>

#ifndef CPPESS_ROOK_H
#define CPPESS_ROOK_H

class Rook {
private:
    int position_x;
    int position_y;
public:
    Rook(const int &position_x, const int &position_y): position_x{position_x}, position_y{position_y}{};

    std::vector < std::pair < int, int > > nextPositions(int tableSize) const;

};

#endif //CPPESS_ROOK_H
