//
// Created by User on 17/09/2022.
//

#include <vector>

#ifndef CPPESS_KNIGHT_H
#define CPPESS_KNIGHT_H

class Knight {
private:
    int position_x;
    int position_y;
public:
    Knight(const int &position_x, const int &position_y): position_x{position_x}, position_y{position_y}{};

    [[nodiscard]] std::vector < std::pair < int, int > > nextPositions(const int &tableSize) const;

};

#endif //CPPESS_KNIGHT_H
