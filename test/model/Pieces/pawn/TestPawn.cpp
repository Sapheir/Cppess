//
// Created by Turca Vasile
//

#include <gtest/gtest.h>
#include <algorithm>

#include "model/pieces/pawn/Pawn.h"

TEST(Pawn, MiddlePawn) {
    int pawnX = 5;
    int pawnY = 2;
    int tableSize = 10;
    colors color = black;
    Pawn pawn{pawnX, pawnY, color};

    auto positions = pawn.nextPositions(tableSize);
    // Check if there is the expected number of possible moves and check if all expected positions are in vector
    sort(positions.begin(), positions.end());

    ASSERT_TRUE(positions.size() == 4);

    ASSERT_TRUE(positions[0].first == pawnX - 1);
    ASSERT_TRUE(positions[0].second == pawnY + 1);

    ASSERT_TRUE(positions[1].first == pawnX);
    ASSERT_TRUE(positions[1].second == pawnY + 1);

    ASSERT_TRUE(positions[2].first == pawnX);
    ASSERT_TRUE(positions[2].second == pawnY + 2);

    ASSERT_TRUE(positions[3].first == pawnX + 1);
    ASSERT_TRUE(positions[3].second == pawnY + 1);
}

TEST(Pawn, LeftPawn){
    int pawnX = 1;
    int pawnY = 2;
    int tableSize = 10;
    colors color = black;
    Pawn pawn{pawnX, pawnY, color};

    auto positions = pawn.nextPositions(tableSize);
    // Check if there is the expected number of possible moves and check if all expected positions are in vector
    sort(positions.begin(), positions.end());

    ASSERT_TRUE(positions.size() == 3);

    ASSERT_TRUE(positions[0].first == pawnX);
    ASSERT_TRUE(positions[0].second == pawnY + 1);

    ASSERT_TRUE(positions[1].first == pawnX);
    ASSERT_TRUE(positions[1].second == pawnY + 2);

    ASSERT_TRUE(positions[2].first == pawnX + 1);
    ASSERT_TRUE(positions[2].second == pawnY + 1);
}

TEST(Pawn, RightPawn){
    int pawnX = 10;
    int pawnY = 2;
    int tableSize = 10;
    colors color = black;
    Pawn pawn{pawnX, pawnY, color};

    auto positions = pawn.nextPositions(tableSize);
    // Check if there is the expected number of possible moves and check if all expected positions are in vector
    sort(positions.begin(), positions.end());

    ASSERT_TRUE(positions.size() == 3);

    ASSERT_TRUE(positions[0].first == pawnX - 1);
    ASSERT_TRUE(positions[0].second == pawnY + 1);

    ASSERT_TRUE(positions[1].first == pawnX);
    ASSERT_TRUE(positions[1].second == pawnY + 1);

    ASSERT_TRUE(positions[2].first == pawnX);
    ASSERT_TRUE(positions[2].second == pawnY + 2);
}

TEST(Pawn, upPawn) {
    int pawnX = 5;
    int pawnY = 10;
    int tableSize = 10;
    colors color = black;
    Pawn pawn{pawnX, pawnY, color};

    auto positions = pawn.nextPositions(tableSize);
    sort(positions.begin(), positions.end());
    // Check if there is the expected number of possible moves

    ASSERT_TRUE(positions.empty());
}

