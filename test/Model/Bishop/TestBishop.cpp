//
// Created by User on 23/09/2022.
//
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "Model/Bishop/Bishop.h"

#include <iostream>

TEST(Bishop, nextPositions_test1) {
    Bishop bishop{5, 5};

    auto positions = bishop.nextPositions(10);
    sort(positions.begin(), positions.end());
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

TEST(Bishop, nextPositions_test2){
    Bishop bishop{1, 1};
    auto positions = bishop.nextPositions(10);
    sort(positions.begin(), positions.end());
    ASSERT_TRUE(positions.size() == 9);
    for(int i = 0 ; i < positions.size() ; i++) {
        ASSERT_TRUE(positions[i].first == i + 2);
        ASSERT_TRUE(positions[i].second == i + 2);
    }
}

TEST(Bishop, nextPositions_test3){
    Bishop bishop{10, 10};
    auto positions = bishop.nextPositions(10);
    sort(positions.begin(), positions.end());
    ASSERT_TRUE(positions.size() == 9);
    for(int i = 0 ; i < positions.size() ; i++) {
        ASSERT_TRUE(positions[i].first == i + 1);
        ASSERT_TRUE(positions[i].second == i + 1);
    }
}

TEST(Bishop, nextPositions_test4){
    Bishop bishop{1, 10};
    auto positions = bishop.nextPositions(10);
    sort(positions.begin(), positions.end());
    ASSERT_TRUE(positions.size() == 9);
    for(int i = 0 ; i < positions.size() ; i++) {
        ASSERT_TRUE(positions[i].first == i + 2);
        ASSERT_TRUE(positions[i].second == 9 - i);
    }
}

TEST(Bishop, nextPositions_test5){
    Bishop bishop{10, 1};
    auto positions = bishop.nextPositions(10);
    sort(positions.begin(), positions.end());
    ASSERT_TRUE(positions.size() == 9);
    for(int i = 0 ; i < positions.size() ; i++) {
        std::cout << positions[i].first << " " << positions[i].second << "\n";
        ASSERT_TRUE(positions[i].first == i + 1);
        ASSERT_TRUE(positions[i].second == 10 - i);
    }
}