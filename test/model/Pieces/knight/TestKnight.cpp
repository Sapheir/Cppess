//
// Created by Turca Vasile
//

#include <gtest/gtest.h>
#include <algorithm>

#include "model/pieces/knight/Knight.h"

TEST(Knight, KnightInMiddle) {
    int knightX = 5;
    int knightY = 5;
    int tableSize = 10;
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(tableSize);
    ASSERT_TRUE(positions.size() == 8);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i < positions.size() - 1 ; i++)
        ASSERT_FALSE(positions[i].first == positions[i + 1].first && positions[i].second == positions[i + 1].second);

    for( const auto &[first, second]: positions){
        ASSERT_TRUE( (abs(first - knightX) == 2 && abs(second - knightY) == 1)
                     || (abs(first - knightX) == 1 && abs(second - knightY) == 2) );
        ASSERT_TRUE(first >= 1);
        ASSERT_TRUE(second >= 1);
        ASSERT_TRUE(first <= 10);
        ASSERT_TRUE(second <= 10);
    }
}

TEST(Knight, KnightInLeft){
    int knightX = 1;
    int knightY = 5;
    int tableSize = 10;
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(tableSize);
    ASSERT_TRUE(positions.size() == 4);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i < positions.size() - 1 ; i++)
        ASSERT_FALSE(positions[i].first == positions[i + 1].first && positions[i].second == positions[i + 1].second);

    for( const auto &[first, second]: positions){
        ASSERT_TRUE( (abs(first - knightX) == 2 && abs(second - knightY) == 1)
                     || (abs(first - knightX) == 1 && abs(second - knightY) == 2) );
        ASSERT_TRUE(first >= 1);
        ASSERT_TRUE(second >= 1);
        ASSERT_TRUE(first <= 10);
        ASSERT_TRUE(second <= 10);
    }
}

TEST(Knight, KnightInRight){
    int knightX = 10;
    int knightY = 5;
    int tableSize = 10;
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(tableSize);
    ASSERT_TRUE(positions.size() == 4);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i < positions.size() - 1 ; i++)
        ASSERT_FALSE(positions[i].first == positions[i + 1].first && positions[i].second == positions[i + 1].second);

    for( const auto &[first, second]: positions){
        ASSERT_TRUE( (abs(first - knightX) == 2 && abs(second - knightY) == 1)
                     || (abs(first - knightX) == 1 && abs(second - knightY) == 2) );
        ASSERT_TRUE(first >= 1);
        ASSERT_TRUE(second >= 1);
        ASSERT_TRUE(first <= 10);
        ASSERT_TRUE(second <= 10);
    }
}

TEST(Knight, KnightUp){
    int knightX = 5;
    int knightY = 10;
    int tableSize = 10;
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(tableSize);
    ASSERT_TRUE(positions.size() == 4);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i < positions.size() - 1 ; i++)
        ASSERT_FALSE(positions[i].first == positions[i + 1].first && positions[i].second == positions[i + 1].second);

    for( const auto &[first, second]: positions){
        ASSERT_TRUE( (abs(first - knightX) == 2 && abs(second - knightY) == 1)
                     || (abs(first - knightX) == 1 && abs(second - knightY) == 2) );
        ASSERT_TRUE(first >= 1);
        ASSERT_TRUE(second >= 1);
        ASSERT_TRUE(first <= 10);
        ASSERT_TRUE(second <= 10);
    }
}

TEST(Knight, KnightDown){
    int knightX = 5;
    int knightY = 1;
    int tableSize = 10;
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(tableSize);
    ASSERT_TRUE(positions.size() == 4);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i < positions.size() - 1 ; i++)
        ASSERT_FALSE(positions[i].first == positions[i + 1].first && positions[i].second == positions[i + 1].second);

    for( const auto &[first, second]: positions){
        ASSERT_TRUE( (abs(first - knightX) == 2 && abs(second - knightY) == 1)
                     || (abs(first - knightX) == 1 && abs(second - knightY) == 2) );
        ASSERT_TRUE(first >= 1);
        ASSERT_TRUE(second >= 1);
        ASSERT_TRUE(first <= 10);
        ASSERT_TRUE(second <= 10);
    }
}

TEST(Knight, KnightLeftUpCorner){
    int knightX = 1;
    int knightY = 1;
    int tableSize = 10;
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(tableSize);
    ASSERT_TRUE(positions.size() == 2);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i < positions.size() - 1 ; i++)
        ASSERT_FALSE(positions[i].first == positions[i + 1].first && positions[i].second == positions[i + 1].second);

    for( const auto &[first, second]: positions){
        ASSERT_TRUE( (abs(first - knightX) == 2 && abs(second - knightY) == 1)
                    || (abs(first - knightX) == 1 && abs(second - knightY) == 2) );
        ASSERT_TRUE(first >= 1);
        ASSERT_TRUE(second >= 1);
        ASSERT_TRUE(first <= 10);
        ASSERT_TRUE(second <= 10);
    }
}

TEST(Knight, KnightLeftDownCorner){
    int knightX = 1;
    int knightY = 10;
    int tableSize = 10;
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(tableSize);
    ASSERT_TRUE(positions.size() == 2);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i < positions.size() - 1 ; i++)
        ASSERT_FALSE(positions[i].first == positions[i + 1].first && positions[i].second == positions[i + 1].second);

    for( const auto &[first, second]: positions){
        ASSERT_TRUE( (abs(first - knightX) == 2 && abs(second - knightY) == 1)
                     || (abs(first - knightX) == 1 && abs(second - knightY) == 2) );
        ASSERT_TRUE(first >= 1);
        ASSERT_TRUE(second >= 1);
        ASSERT_TRUE(first <= 10);
        ASSERT_TRUE(second <= 10);
    }
}


TEST(Knight, KnightRightUpCorner){
    int knightX = 10;
    int knightY = 1;
    int tableSize = 10;
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(tableSize);
    ASSERT_TRUE(positions.size() == 2);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i < positions.size() - 1 ; i++)
        ASSERT_FALSE(positions[i].first == positions[i + 1].first && positions[i].second == positions[i + 1].second);

    for( const auto &[first, second]: positions){
        ASSERT_TRUE( (abs(first - knightX) == 2 && abs(second - knightY) == 1)
                     || (abs(first - knightX) == 1 && abs(second - knightY) == 2) );
        ASSERT_TRUE(first >= 1);
        ASSERT_TRUE(second >= 1);
        ASSERT_TRUE(first <= 10);
        ASSERT_TRUE(second <= 10);
    }
}

TEST(Knight, KnightRightDownCorner){
    int knightX = 10;
    int knightY = 10;
    int tableSize = 10;
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(tableSize);
    ASSERT_TRUE(positions.size() == 2);
    sort(positions.begin(), positions.end());
    for(int i = 0 ; i < positions.size() - 1 ; i++)
        ASSERT_FALSE(positions[i].first == positions[i + 1].first && positions[i].second == positions[i + 1].second);

    for( const auto &[first, second]: positions){
        ASSERT_TRUE( (abs(first - knightX) == 2 && abs(second - knightY) == 1)
                     || (abs(first - knightX) == 1 && abs(second - knightY) == 2) );
        ASSERT_TRUE(first >= 1);
        ASSERT_TRUE(second >= 1);
        ASSERT_TRUE(first <= 10);
        ASSERT_TRUE(second <= 10);
    }
}
