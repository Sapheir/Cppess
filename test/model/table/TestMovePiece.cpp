//
// Created by User on 18/12/2022.
//

#include <gtest/gtest.h>
#include <memory>
#include <algorithm>

#include "../src/model/table/Table.h"
#include "model/pieces/bishop/Bishop.h"
#include "model/pieces/king/King.h"
#include "model/pieces/knight/Knight.h"
#include "model/pieces/pawn/Pawn.h"
#include "model/pieces/queen/Queen.h"
#include "model/pieces/rook/Rook.h"

/**
 * TO DO move other types
 */
TEST(tableMovePiece, moveBishop) {
    int posX = 5;
    int posY = 5;
    int newX = 9;
    int newY = 9;
    int tableSize = 10;
    int color = 0;
    std::shared_ptr<Table> table = std::make_unique<Table>(tableSize);

    table->addPiece(std::make_unique<Bishop>(Bishop(posX, posY, color)));

    auto positions = table->availableMovesDestinations(posX, posY);

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

    table->movePiece(posX, posY, newX, newY);

    ASSERT_TRUE(table->getPiece(posX, posY) == nullptr);
    ASSERT_TRUE(table->getPiece(newX, newY) != nullptr);
    ASSERT_TRUE(table->getPiece(newX, newY)->getX() == newX);
    ASSERT_TRUE(table->getPiece(newX, newY)->getY() == newY);
}
