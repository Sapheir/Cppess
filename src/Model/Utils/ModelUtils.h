//
// Created by User on 17/09/2022.
//

#ifndef CPPESS_MODELUTILS_H
#define CPPESS_MODELUTILS_H

#include <vector>

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
auto addPositions(const int &scaleX, const int &scaleY,
                  const int &initialX, const int &initialY, int tableSize);

#endif //CPPESS_MODELUTILS_H
