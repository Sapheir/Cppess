//
// Created by User on 24/09/2022.
//

#include <gtest/gtest.h>
#include <algorithm>

#include "Model/Knight/Knight.h"

TEST(Knight, KnightInMiddle){
    int knightX = 5;
    int knightY = 5;
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(10);
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
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(10);
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
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(10);
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
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(10);
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
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(10);
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
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(10);
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
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(10);
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
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(10);
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
    Knight knight{knightX,knightY};

    auto positions = knight.nextPositions(10);
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
