//
// Created by Turca Vasile
//
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "model/pieces/bishop/Bishop.h"

TEST(Bishop, nextPositions_test1) {
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    Bishop bishop{posX, posY};

    auto positions = bishop.nextPositions(tableSize);
    sort(positions.begin(), positions.end());
    // Check if there is the expected number of possible moves and check if all expected positions are in vector
    ASSERT_TRUE(17 == positions.size());
    for (int i = 0; i < 8; i += 2) {
        ASSERT_TRUE(positions[i].first == i / 2 + 1);
        ASSERT_TRUE(positions[i].second == i / 2 + 1);
        ASSERT_TRUE(positions[i + 1].first == i / 2 + 1);
        ASSERT_TRUE(positions[i + 1].second == 9 - i / 2);
    }
    for (int i = 8; i < 16; i += 2) {
        ASSERT_TRUE(positions[i].first == i / 2 + 2);
        ASSERT_TRUE(positions[i].second == 8 - i / 2);
        ASSERT_TRUE(positions[i + 1].first == i / 2 + 2);
        ASSERT_TRUE(positions[i + 1].second == i / 2 + 2);
    }
    ASSERT_TRUE(positions[16].first == 10 && positions[16].second == 10);
}

TEST(Bishop, nextPositions_test2) {
    int posX = 1;
    int posY = 1;
    int tableSize = 10;
    Bishop bishop{posX, posY};

    auto positions = bishop.nextPositions(tableSize);
    sort(positions.begin(), positions.end());
    // Check if there is the expected number of possible moves and check if all expected positions are in vector
    ASSERT_TRUE(positions.size() == 9);
    for(int i = 0 ; i < positions.size() ; i++) {
        ASSERT_TRUE(positions[i].first == i + 2);
        ASSERT_TRUE(positions[i].second == i + 2);
    }
}

TEST(Bishop, nextPositions_test3) {
    int posX = 10;
    int posY = 10;
    int tableSize = 10;
    Bishop bishop{posX, posY};

    auto positions = bishop.nextPositions(tableSize);
    sort(positions.begin(), positions.end());
    // Check if there is the expected number of possible moves and check if all expected positions are in vector
    ASSERT_TRUE(positions.size() == 9);
    for(int i = 0 ; i < positions.size() ; i++) {
        ASSERT_TRUE(positions[i].first == i + 1);
        ASSERT_TRUE(positions[i].second == i + 1);
    }
}

TEST(Bishop, nextPositions_test4) {
    int posX = 1;
    int posY = 10;
    int tableSize = 10;
    Bishop bishop{posX, posY};

    auto positions = bishop.nextPositions(tableSize);
    sort(positions.begin(), positions.end());
    // Check if there is the expected number of possible moves and check if all expected positions are in vector
    ASSERT_TRUE(positions.size() == 9);
    for(int i = 0 ; i < positions.size() ; i++) {
        ASSERT_TRUE(positions[i].first == i + 2);
        ASSERT_TRUE(positions[i].second == 9 - i);
    }
}

TEST(Bishop, nextPositions_test5) {
    int posX = 10;
    int posY = 1;
    int tableSize = 10;
    Bishop bishop{posX, posY};

    auto positions = bishop.nextPositions(tableSize);
    sort(positions.begin(), positions.end());
    // Check if there is the expected number of possible moves and check if all expected positions are in vector
    ASSERT_TRUE(positions.size() == 9);
    for(int i = 0 ; i < positions.size() ; i++) {
        ASSERT_TRUE(positions[i].first == i + 1);
        ASSERT_TRUE(positions[i].second == 10 - i);
    }
}
