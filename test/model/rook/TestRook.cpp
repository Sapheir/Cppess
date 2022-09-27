//
// Created by User on 25/09/2022.
//

#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>

#include "model/pieces/rook/Rook.h"

TEST(Rook, RookInMiddle){
    int rookX = 5;
    int rookY = 5;
    Rook rook{rookX, rookY};

    auto positions = rook.nextPositions(10);
    ASSERT_TRUE(positions.size() == 18);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i <= 3 ; i++){
        ASSERT_TRUE(positions[i].first == i + 1);
        ASSERT_TRUE(positions[i].second == rookY);
    }
    for(int i = 4 ; i <= 7 ; i++){
        ASSERT_TRUE(positions[i].first == rookX);
        ASSERT_TRUE(positions[i].second == i - 3);
    }
    for(int i = 8 ; i <= 12 ; i++){
        ASSERT_TRUE(positions[i].first == rookX);
        ASSERT_TRUE(positions[i].second == i - 2);
    }
    for(int i = 13 ; i <= 17 ; i++){
        ASSERT_TRUE(positions[i].first == i - 7);
        ASSERT_TRUE(positions[i].second == rookY);
    }
}

TEST(Rook, RookInLeft){
    int rookX = 1;
    int rookY = 5;
    Rook rook{rookX, rookY};

    auto positions = rook.nextPositions(10);
    ASSERT_TRUE(positions.size() == 18);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i <= 3 ; i++){
        ASSERT_TRUE(positions[i].first == rookX);
        ASSERT_TRUE(positions[i].second == i + 1);
    }
    for(int i = 4 ; i <= 8 ; i++){
        ASSERT_TRUE(positions[i].first == rookX);
        ASSERT_TRUE(positions[i].second == i + 2);
    }
    for(int i = 9 ; i <= 17 ; i++){
        ASSERT_TRUE(positions[i].first == i - 7);
        ASSERT_TRUE(positions[i].second == rookY);
    }
}

TEST(Rook, RookInRight){
    int rookX = 10;
    int rookY = 5;
    Rook rook{rookX, rookY};

    auto positions = rook.nextPositions(10);
    ASSERT_TRUE(positions.size() == 18);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i <= 8 ; i++){
        ASSERT_TRUE(positions[i].first == i + 1);
        ASSERT_TRUE(positions[i].second == rookY);
    }
    for(int i = 9 ; i <= 12 ; i++){
        ASSERT_TRUE(positions[i].first == rookX);
        ASSERT_TRUE(positions[i].second == i - 8);
    }
    for(int i = 13 ; i <= 17 ; i++){
        ASSERT_TRUE(positions[i].first == rookX);
        ASSERT_TRUE(positions[i].second == i - 7);
    }
}

TEST(Rook, RookUp){
    int rookX = 5;
    int rookY = 10;
    Rook rook{rookX, rookY};

    auto positions = rook.nextPositions(10);
    ASSERT_TRUE(positions.size() == 18);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i <= 3 ; i++){
        ASSERT_TRUE(positions[i].first == i + 1);
        ASSERT_TRUE(positions[i].second == rookY);
    }
    for(int i = 4 ; i <= 12 ; i++){
        ASSERT_TRUE(positions[i].first == rookX);
        ASSERT_TRUE(positions[i].second == i - 3);
    }
    for(int i = 13 ; i <= 17 ; i++){
        ASSERT_TRUE(positions[i].first == i - 7);
        ASSERT_TRUE(positions[i].second == rookY);
    }
}

TEST(Rook, RookDown){
    int rookX = 5;
    int rookY = 1;
    Rook rook{rookX, rookY};

    auto positions = rook.nextPositions(10);
    ASSERT_TRUE(positions.size() == 18);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i <= 3 ; i++){
        ASSERT_TRUE(positions[i].first == i + 1);
        ASSERT_TRUE(positions[i].second == rookY);
    }
    for(int i = 4 ; i <= 12 ; i++){
        ASSERT_TRUE(positions[i].first == rookX);
        ASSERT_TRUE(positions[i].second == i - 2);
    }
    for(int i = 13 ; i <= 17 ; i++){
        ASSERT_TRUE(positions[i].first == i - 7);
        ASSERT_TRUE(positions[i].second == rookY);
    }
}

TEST(Rook, RookLeftUp){
    int rookX = 1;
    int rookY = 10;
    Rook rook{rookX, rookY};

    auto positions = rook.nextPositions(10);
    ASSERT_TRUE(positions.size() == 18);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i <= 8 ; i++){
        ASSERT_TRUE(positions[i].first == rookX);
        ASSERT_TRUE(positions[i].second == i + 1);
    }
    for(int i = 9 ; i <= 17 ; i++){
        ASSERT_TRUE(positions[i].first == i - 7);
        ASSERT_TRUE(positions[i].second == rookY);
    }
}

TEST(Rook, RookRightUp){
    int rookX = 10;
    int rookY = 10;
    Rook rook{rookX, rookY};

    auto positions = rook.nextPositions(10);
    ASSERT_TRUE(positions.size() == 18);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i <= 8 ; i++){
        ASSERT_TRUE(positions[i].first == i + 1);
        ASSERT_TRUE(positions[i].second == rookY);
    }
    for(int i = 9 ; i <= 17 ; i++){
        ASSERT_TRUE(positions[i].first == rookX);
        ASSERT_TRUE(positions[i].second == i - 8);
    }
}

TEST(Rook, RookLeftDown){
    int rookX = 1;
    int rookY = 1;
    Rook rook{rookX, rookY};

    auto positions = rook.nextPositions(10);
    ASSERT_TRUE(positions.size() == 18);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i <= 8 ; i++){
        ASSERT_TRUE(positions[i].first == rookX);
        ASSERT_TRUE(positions[i].second == i + 2);
    }
    for(int i = 9 ; i <= 17 ; i++){
        ASSERT_TRUE(positions[i].first == i - 7);
        ASSERT_TRUE(positions[i].second == rookY);
    }
}

TEST(Rook, RookRightDown){
    int rookX = 10;
    int rookY = 1;
    Rook rook{rookX, rookY};

    auto positions = rook.nextPositions(10);
    ASSERT_TRUE(positions.size() == 18);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i <= 8 ; i++){
        ASSERT_TRUE(positions[i].first == i + 1);
        ASSERT_TRUE(positions[i].second == rookY);
    }
    for(int i = 9 ; i <= 17 ; i++){
        ASSERT_TRUE(positions[i].first == rookX);
        ASSERT_TRUE(positions[i].second == i - 7);
    }
}
