//
// Created by Turca Vasile
//

#ifndef CPPESS_MODELUTILS_H
#define CPPESS_MODELUTILS_H

#include <vector>

class ModelUtils {
public:

    /*
     * Check if a coordinate is in range [1, limit]
     *
     * @param position: the coordinate that will be checked
     *
     * return true or false if the coordinate is in range
     */
    static bool inRange(const int  &position, const int &limit);

    /*
     * Check if possible new coordinates for a piece are inside the table
     *
     * @param newPositionX, newPositionY: possible new position of the piece on the chess board
     * @param tableSize: the size of the table
     *
     * return true if the current potential position is on table and false otherwise
     */
    static bool insideTable(const int& newPositionX, const int& newPositionY, const int &tableSize);

    /*
    * Generate all possible movements from the initial position inside the chess table
    *
    * @param initialX, initialY: initial position of the piece on the chess board
    * @param scaleX: parameters that show if the position on X should increase(1) or decrease(-1)
    * @param scaleY: parameters that show if the position on Y should increase(1) or decrease(-1)
    * @param tableSize: the size of the table
    *
    * @return vector < pair < int, int > > - all generated positions
    */
    static std::vector < std::pair < int, int > > addPositions(const int &scaleX, const int &scaleY,
                                                              const int &initialX, const int &initialY, const int &tableSize);


};

#endif //CPPESS_MODELUTILS_H
