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
 * TO DO remove other types
 */
TEST(tableRemove, removeBishopFromTable) {
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    colors color = black;
    std::unique_ptr<Table> table = std::make_unique<Table>(tableSize);

    table->addPiece(std::make_unique<Bishop>(Bishop(posX, posY, color)));

    ASSERT_TRUE(table->getPiece(posX, posY) != nullptr);

    table->removePiece(posX, posY);

    for(int x = 0 ; x <= tableSize ; x++)
        for(int y = 0 ; y <= tableSize ; y++)
            ASSERT_TRUE(table->getPiece(x, y) == nullptr);
}