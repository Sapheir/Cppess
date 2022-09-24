//
// Created by User on 25/09/2022.
//

#include <gtest/gtest.h>
#include <algorithm>

#include "Model/Pawn/Pawn.h"

TEST(Pawn, MiddlePawn){
    int pawnX = 5;
    int pawnY = 2;
    Pawn pawn{pawnX, pawnY};

    auto positions = pawn.nextPositions(10);
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
    Pawn pawn{pawnX, pawnY};

    auto positions = pawn.nextPositions(10);
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
    Pawn pawn{pawnX, pawnY};

    auto positions = pawn.nextPositions(10);
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
    Pawn pawn{pawnX, pawnY};

    auto positions = pawn.nextPositions(10);
    sort(positions.begin(), positions.end());

    ASSERT_TRUE(positions.size() == 0);
}

