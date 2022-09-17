//
// Created by User on 16/09/2022.
//

#include <vector>

#ifndef CPPESS_PAWN_H
#define CPPESS_PAWN_H

class Pawn {
private:
    int position_x;
    int position_y;

    bool doubleMoveAvailable;
public:
    Pawn(const int &position_x, const int &position_y): position_x{position_x}, position_y{position_y}{
        doubleMoveAvailable = true;
    };

    [[nodiscard]] std::vector < std::pair < int, int > > nextPositions(int tableSize) const;

};

#endif //CPPESS_PAWN_H
