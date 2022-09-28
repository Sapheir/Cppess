//
// Created by Turca Vasile
//

#include <vector>

#ifndef CPPESS_PIECE_H
#define CPPESS_PIECE_H

class Piece {
protected:
    int positionX;
    int positionY;
public:

    /* Constructor for piece */
    Piece(const int &positionX, const int &positionY): positionX{positionX}, positionY{positionY}{};

    /*
     * Return a list of all possible positions inside the chess table where the bishop could be moved
     *
     * @param tableSize: the size of the table
     *
     * @return vector < pair < int, int > > - all possible positions
     */
    [[nodiscard]] virtual std::vector < std::pair < int, int > > nextPositions(const int &tableSize) const = 0;

    /*
     * Get the offset on X of the piece as an int
     */
    [[nodiscard]] int getX() const;

    /*
     * Get the offset on Y of the piece as an int
     */
    [[nodiscard]] int getY() const;

};


#endif //CPPESS_PIECE_H
