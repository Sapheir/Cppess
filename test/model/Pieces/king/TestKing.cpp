//
// Created by Turca Vasile
//

#include <gtest/gtest.h>
#include <algorithm>

#include "model/pieces/king/King.h"

TEST(King, KingInMiddle) {
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    colors color = black;
    King king{posX, posY, color};

    auto positions = king.nextPositions(tableSize);
    // Check if there is the expected number of possible moves and check if all expected positions are in vector
    ASSERT_TRUE(positions.size() == 8);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i < 3 ; i++){
        ASSERT_TRUE(positions[i].first == 4);
        ASSERT_TRUE(positions[i].second == i + 4);
    }

    ASSERT_TRUE(positions[3].first == 5);
    ASSERT_TRUE(positions[3].second == 4);

    ASSERT_TRUE(positions[4].first == 5);
    ASSERT_TRUE(positions[4].second == 6);

    for(int i = 5 ; i < 8 ; i++){
        ASSERT_TRUE(positions[i].first == 6);
        ASSERT_TRUE(positions[i].second == i - 1);
    }
}

TEST(King, KingInLeft){
    int posX = 1;
    int posY = 5;
    int tableSize = 10;
    colors color = black;
    King king{posX, posY, color};

    auto positions = king.nextPositions(tableSize);
    // Check if there is the expected number of possible moves and check if all expected positions are in vector
    ASSERT_TRUE(positions.size() == 5);
    sort(positions.begin(), positions.end());

    ASSERT_TRUE(positions[0].first == 1);
    ASSERT_TRUE(positions[0].second == 4);

    ASSERT_TRUE(positions[1].first == 1);
    ASSERT_TRUE(positions[1].second == 6);

    for(int i = 2 ; i < 5 ; i++){
        ASSERT_TRUE(positions[i].first == 2);
        ASSERT_TRUE(positions[i].second == i + 2);
    }
}

TEST(King, KingInRight){
    int posX = 10;
    int posY = 5;
    int tableSize = 10;
    colors color = black;
    King king{posX, posY, color};

    auto positions = king.nextPositions(tableSize);
    // Check if there is the expected number of possible moves and check if all expected positions are in vector
    ASSERT_TRUE(positions.size() == 5);
    sort(positions.begin(), positions.end());

    for(int i = 0 ; i < 3 ; i++){
        ASSERT_TRUE(positions[i].first == 9);
        ASSERT_TRUE(positions[i].second == i + 4);
    }
    ASSERT_TRUE(positions[3].first == 10);
    ASSERT_TRUE(positions[3].second == 4);

    ASSERT_TRUE(positions[4].first == 10);
    ASSERT_TRUE(positions[4].second == 6);

}

TEST(King, KingOnTop){
    int posX = 5;
    int posY = 10;
    int tableSize = 10;
    colors color = black;
    King king{posX, posY, color};

    auto positions = king.nextPositions(tableSize);
    // Check if there is the expected number of possible moves and check if all expected positions are in vector
    ASSERT_TRUE(positions.size() == 5);
    sort(positions.begin(), positions.end());

    for(int i = 0 ; i < 2 ; i++){
        ASSERT_TRUE(positions[i].first == 4);
        ASSERT_TRUE(positions[i].second == i + 9);
    }
    ASSERT_TRUE(positions[2].first == 5);
    ASSERT_TRUE(positions[2].second == 9);

    for(int i = 3 ; i < 5 ; i++){
        ASSERT_TRUE(positions[i].first == 6);
        ASSERT_TRUE(positions[i].second == i + 6);
    }
}

TEST(King, KingOnDown){
    int posX = 5;
    int posY = 1;
    int tableSize = 10;
    colors color = black;
    King king{posX, posY, color};

    auto positions = king.nextPositions(tableSize);

    // Check if there is the expected number of possible moves and check if all expected positions are in vector
    ASSERT_TRUE(positions.size() == 5);
    sort(positions.begin(), positions.end());

    for(int i = 0 ; i < 2 ; i++){
        ASSERT_TRUE(positions[i].first == 4);
        ASSERT_TRUE(positions[i].second == i + 1);
    }
    ASSERT_TRUE(positions[2].first == 5);
    ASSERT_TRUE(positions[2].second == 2);

    for(int i = 3 ; i < 5 ; i++){
        ASSERT_TRUE(positions[i].first == 6);
        ASSERT_TRUE(positions[i].second == i - 2);
    }
}
