//
// Created by User on 27/09/2022.
//

#include <vector>

#ifndef CPPESS_PIECE_H
#define CPPESS_PIECE_H

class Piece{
private:
    
public:
    [[nodiscard]] virtual std::vector < std::pair < int, int > > nextPositions(const int &tableSize) const = 0;

};

#endif //CPPESS_PIECE_H
