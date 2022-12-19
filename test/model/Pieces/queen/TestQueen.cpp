//
// Created by Turca Vasile
//

#include <gtest/gtest.h>
#include <algorithm>

#include "model/pieces/queen/Queen.h"
#include "model/pieces/rook/Rook.h"
#include "model/pieces/bishop/Bishop.h"

#define pint std::pair < int, int >
#define vpint std::vector < pint>

bool pairCompareEq(const pint &X, const pint &Y) {
    return (X.first == Y.first && X.second == Y.second);
}

void testSameContentOnMerge(const vpint &x, const vpint &y, const vpint &z) {
    /* Compare elements */
    int indexX = 0, indexY = 0, indexZ = 0;
    while(indexX < x.size() && indexY < y.size()){
        if(pairCompareEq(x[indexX], z[indexZ])){
            indexX++;
            indexZ++;
            continue;
        }
        if(pairCompareEq(y[indexY], z[indexZ])){
            indexY++;
            indexZ++;
            continue;
        }
        ASSERT_TRUE(false);
    }
    while(indexX < x.size()) {
        if (pairCompareEq(x[indexX], z[indexZ])) {
            indexX++;
            indexZ++;
            continue;
        }
        ASSERT_TRUE(false);
    }
    while(indexY < y.size()){
        if(pairCompareEq(y[indexY], z[indexZ])){
            indexY++;
            indexZ++;
            continue;
        }
        ASSERT_TRUE(false);
    }
}

void sortAll3Vectors(vpint &x, vpint &y, vpint &z){
    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());
    std::sort(z.begin(), z.end());

}

void testRookPlusBishopEqualQueen(const int &posX, const int &posY, const int &color, const int &tableSize){
    Rook rook{posX, posY, color};
    Bishop bishop{posX, posY, color};
    Queen queen{posX, posY, color};

    auto rookPositions = rook.nextPositions(tableSize);
    auto bishopPositions = bishop.nextPositions(tableSize);
    auto queenPositions = queen.nextPositions(tableSize);

    /* In order to have same elements, we firstly need same size */
    ASSERT_TRUE(rookPositions.size() + bishopPositions.size() == queenPositions.size());

    sortAll3Vectors(rookPositions, bishopPositions, queenPositions);

    /* Check if queen vector has the right set of positions */
    testSameContentOnMerge(rookPositions, bishopPositions, queenPositions);

}

TEST(Queen, QueenInMiddle){
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    int color = 10;
    testRookPlusBishopEqualQueen(posX, posY, color, tableSize);
}

TEST(Queen, QueenInLeft){
    int posX = 1;
    int posY = 5;
    int tableSize = 10;
    int color = 10;
    testRookPlusBishopEqualQueen(posX, posY, color, tableSize);
}

TEST(Queen, QueenInRight){
    int posX = 10;
    int posY = 5;
    int tableSize = 10;
    int color = 10;
    testRookPlusBishopEqualQueen(posX, posY, color, tableSize);
}

TEST(Queen, QueenUp){
    int posX = 5;
    int posY = 10;
    int tableSize = 10;
    int color = 10;
    testRookPlusBishopEqualQueen(posX, posY, color, tableSize);
}

TEST(Queen, QueenDown){
    int posX = 5;
    int posY = 1;
    int tableSize = 10;
    int color = 10;
    testRookPlusBishopEqualQueen(posX, posY, color, tableSize);
}

TEST(Queen, QueenUpLeft){
    int posX = 1;
    int posY = 10;
    int tableSize = 10;
    int color = 10;
    testRookPlusBishopEqualQueen(posX, posY, color, tableSize);
}

TEST(Queen, QueenUpRight){
    int posX = 10;
    int posY = 10;
    int tableSize = 10;
    int color = 10;
    testRookPlusBishopEqualQueen(posX, posY, color, tableSize);
}

TEST(Queen, QueenDownLeft){
    int posX = 1;
    int posY = 1;
    int tableSize = 10;
    int color = 10;
    testRookPlusBishopEqualQueen(posX, posY, color, tableSize);
}

TEST(Queen, QueenDownRight){
    int posX = 10;
    int posY = 1;
    int tableSize = 10;
    int color = 10;
    testRookPlusBishopEqualQueen(posX, posY, color, tableSize);
}
