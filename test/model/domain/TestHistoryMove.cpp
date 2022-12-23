//
// Created by Turca Vasile on 22/12/2022.
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
#include "model/domain/history/HistoryMove.h"

TEST(testHistoryMove, moveWithoutGeneratedEvents) {
    int posX = 5;
    int posY = 5;
    int newX = 9;
    int newY = 9;
    int tableSize = 10;
    colors color = black;
    colors anotherColor = white;
    std::unique_ptr<Table> table = std::make_unique<Table>(tableSize);
    ServiceTable serviceTable{table, color, anotherColor};

    std::shared_ptr < Bishop > bishop = std::make_unique<Bishop>(Bishop(posX, posY, color));
    serviceTable.addPiece(bishop);

    HistoryMove moveHistory{posX, posY, newX, newY, bishop};

    ASSERT_TRUE(moveHistory.getPiece() == bishop);
    ASSERT_TRUE(moveHistory.getOldX() == posX);
    ASSERT_TRUE(moveHistory.getOldY() == posY);
    ASSERT_TRUE(moveHistory.getNewY() == newX);
    ASSERT_TRUE(moveHistory.getNewY() == newY);
    ASSERT_TRUE(moveHistory.getGeneratedEvents().empty());
}

TEST(testHistoryMove, moveWithCapture) {
    int posX = 5;
    int posY = 5;
    int newX = 9;
    int newY = 9;
    int tableSize = 10;
    colors color = black;
    colors anotherColor = white;
    std::unique_ptr<Table> table = std::make_unique<Table>(tableSize);
    ServiceTable serviceTable{table, color, anotherColor};

    std::shared_ptr < Bishop > bishop = std::make_unique<Bishop>(Bishop(posX, posY, color));
    serviceTable.addPiece(bishop);

    auto positions = serviceTable.availableMovesDestinations(posX, posY);

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

    std::shared_ptr < Pawn > pawn = std::make_unique<Pawn>(newX, newY, anotherColor);
    serviceTable.addPiece(pawn);
    std::vector < std::shared_ptr < BaseEvent > > generatedEvents = serviceTable.movePiece(posX, posY, newX, newY);

    std::shared_ptr < HistoryMove > moveHistory = serviceTable.getLastMoveFromHistory();

    ASSERT_TRUE(moveHistory->getPiece() == bishop);
    ASSERT_TRUE(moveHistory->getOldX() == posX);
    ASSERT_TRUE(moveHistory->getOldY() == posY);
    ASSERT_TRUE(moveHistory->getNewY() == newX);
    ASSERT_TRUE(moveHistory->getNewY() == newY);
    ASSERT_TRUE(moveHistory->getGeneratedEvents().size() == 1);
    ASSERT_TRUE(moveHistory->getGeneratedEvents().begin()->get()->getPiece() == pawn);
    ASSERT_TRUE(moveHistory->getGeneratedEvents().begin()->get()->getEventType() == capture);


}