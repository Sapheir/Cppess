#include <gtest/gtest.h>

#include "Model/Utils/ModelUtils.h"
#include <vector>
#include <algorithm>

/* Test if behaviour with increase only on x*/
TEST(model_utils, addPositions_test_increaseOnX) {
    auto positions1 = ModelUtils::addPositions(1, 0, 10, 10, 20);
    ASSERT_TRUE(positions1.size() == 10);
    sort(positions1.begin(), positions1.end());
    for(int i = 0 ; i < positions1.size() - 1 ; i++){
        ASSERT_TRUE(positions1[i].first == positions1[i + 1].first - 1);
        ASSERT_TRUE(positions1[i].first == 11 + i);
        ASSERT_TRUE(positions1[i].second == 10);
    }

    auto positions2 = ModelUtils::addPositions(1, 0, 9, 16, 25);
    ASSERT_TRUE(positions2.size() == 16);
    sort(positions2.begin(), positions2.end());
    for(int i = 0 ; i < positions2.size() - 1 ; i++){
        ASSERT_TRUE(positions2[i].first == positions2[i + 1].first - 1);
        ASSERT_TRUE(positions2[i].first == 10 + i);
        ASSERT_TRUE(positions2[i].second == 16);
    }

}

/* Test if behaviour with decrease only on x*/
TEST(model_utils, addPositions_test_decreaseOnX) {
    auto positions1 = ModelUtils::addPositions(-1, 0, 10, 10, 20);
    ASSERT_TRUE(positions1.size() == 9);
    sort(positions1.begin(), positions1.end());
    for(int i = 0 ; i < positions1.size() - 1 ; i++){
        ASSERT_TRUE(positions1[i].first == positions1[i + 1].first - 1);
        ASSERT_TRUE(positions1[i].first == i + 1);
        ASSERT_TRUE(positions1[i].second == 10);
    }

    auto positions2 = ModelUtils::addPositions(-1, 0, 25, 16, 25);
    ASSERT_TRUE(positions2.size() == 24);
    sort(positions2.begin(), positions2.end());
    for(int i = 0 ; i < positions2.size() - 1 ; i++){
        ASSERT_TRUE(positions2[i].first == positions2[i + 1].first - 1);
        ASSERT_TRUE(positions2[i].first == i + 1);
        ASSERT_TRUE(positions2[i].second == 16);
    }

}








/* Test if behaviour with increase only on y*/
TEST(model_utils, addPositions_test_increaseOnY) {
    auto positions1 = ModelUtils::addPositions(0, 1, 10, 10, 20);
    ASSERT_TRUE(positions1.size() == 10);
    sort(positions1.begin(), positions1.end());
    for(int i = 0 ; i < positions1.size() - 1 ; i++){
        ASSERT_TRUE(positions1[i].second == positions1[i + 1].second - 1);
        ASSERT_TRUE(positions1[i].second == 11 + i);
        ASSERT_TRUE(positions1[i].first == 10);
    }

    auto positions2 = ModelUtils::addPositions(0, 1, 16, 9, 25);
    ASSERT_TRUE(positions2.size() == 16);
    sort(positions2.begin(), positions2.end());
    for(int i = 0 ; i < positions2.size() - 1 ; i++){
        ASSERT_TRUE(positions2[i].second == positions2[i + 1].second - 1);
        ASSERT_TRUE(positions2[i].second == 10 + i);
        ASSERT_TRUE(positions2[i].first == 16);
    }

}

/* Test if behaviour with decrease only on y*/
TEST(model_utils, addPositions_test_decreaseOnY) {
    auto positions1 = ModelUtils::addPositions(0, -1, 10, 10, 20);
    ASSERT_TRUE(positions1.size() == 9);
    sort(positions1.begin(), positions1.end());
    for(int i = 0 ; i < positions1.size() - 1 ; i++){
        ASSERT_TRUE(positions1[i].second == positions1[i + 1].second - 1);
        ASSERT_TRUE(positions1[i].second == i + 1);
        ASSERT_TRUE(positions1[i].first == 10);
    }

    auto positions2 = ModelUtils::addPositions(0, -1, 16, 25, 25);
    ASSERT_TRUE(positions2.size() == 24);
    sort(positions2.begin(), positions2.end());
    for(int i = 0 ; i < positions2.size() - 1 ; i++){
        ASSERT_TRUE(positions2[i].second == positions2[i + 1].second - 1);
        ASSERT_TRUE(positions2[i].second == i + 1);
        ASSERT_TRUE(positions2[i].first == 16);
    }

}








/* Test if behaviour with both x and y increase */
TEST(model_utils, addPositions_test_increaseXandY) {
    auto positions1 = ModelUtils::addPositions(1, 1, 10, 10, 20);
    ASSERT_TRUE(positions1.size() == 10);
    for(int i = 0 ; i < positions1.size() - 1 ; i++){
        ASSERT_TRUE(positions1[i].first == positions1[i + 1].first - 1);
        ASSERT_TRUE(positions1[i].second == positions1[i + 1].second - 1);
        ASSERT_TRUE(positions1[i].second == i + 11);
        ASSERT_TRUE(positions1[i].first == positions1[i].second);
    }

    auto positions2 = ModelUtils::addPositions(1, 1, 10, 16, 25);
    ASSERT_TRUE(positions2.size() == 9);
    for(int i = 0 ; i < positions2.size() - 1 ; i++){
        ASSERT_TRUE(positions2[i].first == positions2[i + 1].first - 1);
        ASSERT_TRUE(positions2[i].second == positions2[i + 1].second - 1);
        ASSERT_TRUE(positions2[i].first == i + 11);
        ASSERT_TRUE(positions2[i].second <= i + 17);
    }

    auto positions3 = ModelUtils::addPositions(1, 1, 16, 10, 25);
    ASSERT_TRUE(positions3.size() == 9);
    for(int i = 0 ; i < positions3.size() - 1 ; i++){
        ASSERT_TRUE(positions3[i].first == positions3[i + 1].first - 1);
        ASSERT_TRUE(positions3[i].second == positions3[i + 1].second - 1);
        ASSERT_TRUE(positions3[i].first == i + 17);
        ASSERT_TRUE(positions3[i].second <= i + 11);
    }
}








/* Test if behaviour with both x and y decrease */
TEST(model_utils, addPositions_test_decreaseXandY) {
    auto positions1 = ModelUtils::addPositions(-1, -1, 10, 10, 20);
    ASSERT_TRUE(positions1.size() == 9);
    std::sort(positions1.begin(),positions1.end());
    for (int i = 0; i < positions1.size() - 1; i++) {
        ASSERT_TRUE(positions1[i].first == positions1[i + 1].first - 1);
        ASSERT_TRUE(positions1[i].second == positions1[i + 1].second - 1);
        ASSERT_TRUE(positions1[i].second == i + 1);
        ASSERT_TRUE(positions1[i].first == positions1[i].second);
    }

    auto positions2 = ModelUtils::addPositions(-1, -1, 10, 16, 25);
    ASSERT_TRUE(positions2.size() == 9);
    std::sort(positions2.begin(),positions2.end());
    for (int i = 0; i < positions2.size() - 1; i++) {
        ASSERT_TRUE(positions2[i].first == positions2[i + 1].first - 1);
        ASSERT_TRUE(positions2[i].second == positions2[i + 1].second - 1);
        ASSERT_TRUE(positions2[i].first == i + 1);
        ASSERT_TRUE(positions2[i].second <= i + 7);
    }

    auto positions3 = ModelUtils::addPositions(-1, -1, 16, 10, 25);
    ASSERT_TRUE(positions3.size() == 9);
    std::sort(positions3.begin(),positions3.end());
    for (int i = 0; i < positions2.size() - 1; i++) {
        ASSERT_TRUE(positions3[i].first == positions3[i + 1].first - 1);
        ASSERT_TRUE(positions3[i].second == positions3[i + 1].second - 1);
        ASSERT_TRUE(positions3[i].first == i + 7);
        ASSERT_TRUE(positions3[i].second <= i + 1);
    }
}








/* Test if behaviour with increase with both x increase and y decrease */
TEST(model_utils, addPositions_test_increaseXdecreaseY) {
    auto positions1 = ModelUtils::addPositions(1, -1, 10, 10, 20);
    ASSERT_TRUE(positions1.size() == 9);
    for(int i = 0 ; i < positions1.size() - 1 ; i++){
        ASSERT_TRUE(positions1[i].first == positions1[i + 1].first - 1);
        ASSERT_TRUE(positions1[i].second == positions1[i + 1].second + 1);
        ASSERT_TRUE(positions1[i].first == i + 11);
        ASSERT_TRUE(positions1[i].second == 9 - i);
    }

    auto positions2 = ModelUtils::addPositions(1, -1, 11, 16, 25);
    ASSERT_TRUE(positions2.size() == 14);
    for(int i = 0 ; i < positions2.size() - 1 ; i++){
        ASSERT_TRUE(positions2[i].first == positions2[i + 1].first - 1);
        ASSERT_TRUE(positions2[i].second == positions2[i + 1].second + 1);
        ASSERT_TRUE(positions2[i].first == i + 12);
        ASSERT_TRUE(positions2[i].second <= 15 - i);
    }

    auto positions3 = ModelUtils::addPositions(1, -1, 16, 4, 25);
    ASSERT_TRUE(positions3.size() == 3);
    for(int i = 0 ; i < positions3.size() - 1 ; i++){
        ASSERT_TRUE(positions3[i].first == positions3[i + 1].first - 1);
        ASSERT_TRUE(positions3[i].second == positions3[i + 1].second + 1);
        ASSERT_TRUE(positions3[i].first == i + 17);
        ASSERT_TRUE(positions3[i].second <= 3 - i);
    }
}








/* Test if behaviour with increase with both x decrease and y increase */
TEST(model_utils, addPositions_test_decreaseXincreaseY) {
    auto positions1 = ModelUtils::addPositions(-1, 1, 10, 10, 20);
    ASSERT_TRUE(positions1.size() == 9);
    for(int i = 0 ; i < positions1.size() - 1 ; i++){
        ASSERT_TRUE(positions1[i].first == positions1[i + 1].first + 1);
        ASSERT_TRUE(positions1[i].second == positions1[i + 1].second - 1);
        ASSERT_TRUE(positions1[i].first == 9 - i);
        ASSERT_TRUE(positions1[i].second == 11 + i);
    }

    auto positions2 = ModelUtils::addPositions(-1, 1, 11, 16, 25);
    ASSERT_TRUE(positions2.size() == 9);
    for(int i = 0 ; i < positions2.size() - 1 ; i++){
        ASSERT_TRUE(positions2[i].first == positions2[i + 1].first + 1);
        ASSERT_TRUE(positions2[i].second == positions2[i + 1].second - 1);
        ASSERT_TRUE(positions2[i].first == 10 - i);
        ASSERT_TRUE(positions2[i].second <= 17 + i);
    }

    auto positions3 = ModelUtils::addPositions(-1, 1, 16, 4, 25);
    ASSERT_TRUE(positions3.size() == 15);
    for(int i = 0 ; i < positions3.size() - 1 ; i++){
        ASSERT_TRUE(positions3[i].first == positions3[i + 1].first + 1);
        ASSERT_TRUE(positions3[i].second == positions3[i + 1].second - 1);
        ASSERT_TRUE(positions3[i].first == 15 - i);
        ASSERT_TRUE(positions3[i].second <= 5 + i);
    }
}