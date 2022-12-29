//
// Created by Turca on 23/12/2022.
//

#include <gtest/gtest.h>
#include <memory>
#include <algorithm>

#include "../src/model/table/Table.h"
#include "model/domain/pieces/bishop/Bishop.h"
#include "model/domain/pieces/king/King.h"
#include "model/domain/pieces/knight/Knight.h"
#include "model/domain/pieces/pawn/Pawn.h"
#include "model/domain/pieces/queen/Queen.h"
#include "model/domain/pieces/rook/Rook.h"
#include "model/services/ServiceTable.h"

TEST(testHistory, TestAddInHistory) {
    int tableSize = 10;
    int posX = 2;
    int posY = tableSize - 1;
    int newX = 2;
    int newY = tableSize;

    colors color = black;
    colors anotherColor = white;
    std::unique_ptr<Table> table = std::make_unique<Table>(tableSize);
    ServiceTable serviceTable{table, color, anotherColor};

    std::shared_ptr < Pawn > pawn = std::make_unique<Pawn>(Pawn(posX, posY, color));
    serviceTable.addPiece(pawn);

    auto generatedEvents = serviceTable.movePiece(posX, posY, newX, newY);
    ASSERT_TRUE(generatedEvents.size() == 1);
    ASSERT_TRUE(generatedEvents.begin()->get()->getEventType() == pawn_promotion);
    ASSERT_TRUE(generatedEvents.begin()->get()->getPiece() == pawn);

    auto lastRegisterFromHistory = serviceTable.getLastMoveFromHistory();
    ASSERT_TRUE(lastRegisterFromHistory->getPiece() == pawn);
    ASSERT_TRUE(lastRegisterFromHistory->getGeneratedEvents().size() == 1);
    ASSERT_TRUE(lastRegisterFromHistory->getGeneratedEvents().begin()->get()->getEventType() == pawn_promotion);
    ASSERT_TRUE(lastRegisterFromHistory->getGeneratedEvents().begin()->get()->getPiece() == pawn);

}