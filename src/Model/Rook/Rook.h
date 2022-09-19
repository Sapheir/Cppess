//
// Created by User on 17/09/2022.
//

#include <vector>

#include "../Utils/ModelUtils.h"

#ifndef CPPESS_ROOK_H
#define CPPESS_ROOK_H

class Rook {
private:
    int position_x;
    int position_y;
public:
    Rook(const int &position_x, const int &position_y): position_x{position_x}, position_y{position_y}{};

    [[nodiscard]] std::vector < std::pair < int, int > > nextPositions(const int &tableSize) const;

};

#endif //CPPESS_ROOK_H
