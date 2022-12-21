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
#include "model/services/ServiceTable.h"

/**
 * TO DO move other types
 */
TEST(tableMovePiece, moveBishopBasic) {
    int posX = 5;
    int posY = 5;
    int newX = 9;
    int newY = 9;
    int tableSize = 10;
    colors color = black;
    std::unique_ptr<Table> table = std::make_unique<Table>(tableSize);
    ServiceTable serviceTable{table, black};

    serviceTable.addPiece(std::make_unique<Bishop>(Bishop(posX, posY, color)));

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

    serviceTable.movePiece(posX, posY, newX, newY);

    ASSERT_TRUE(serviceTable.getPiece(posX, posY) == nullptr);
    ASSERT_TRUE(serviceTable.getPiece(newX, newY) != nullptr);
    ASSERT_TRUE(serviceTable.getPiece(newX, newY)->getX() == newX);
    ASSERT_TRUE(serviceTable.getPiece(newX, newY)->getY() == newY);

    serviceTable.addPiece(std::make_unique<Bishop>(posX, posY, white));
    serviceTable.movePiece(newX, newY, posX, posY);

    ASSERT_TRUE(serviceTable.getPiece(newX, newY) == nullptr);
    ASSERT_TRUE(serviceTable.getPiece(posX, posY) != nullptr);
    ASSERT_TRUE(serviceTable.getPiece(posX, posY)->getX() == posX);
    ASSERT_TRUE(serviceTable.getPiece(posX, posY)->getY() == posY);
}

TEST(tableMovePiece, moveBishopCapturedPiece) {
    int posX = 5;
    int posY = 5;
    int newX = 9;
    int newY = 9;
    int tableSize = 10;
    colors color = black;
    colors anotherColor = white;
    std::unique_ptr<Table> table = std::make_unique<Table>(tableSize);
    ServiceTable serviceTable{table, color};

    serviceTable.addPiece(std::make_unique<Bishop>(Bishop(posX, posY, color)));

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
    auto generatedEvents = serviceTable.movePiece(posX, posY, newX, newY);

    ASSERT_TRUE(generatedEvents.size() == 1);
    ASSERT_TRUE(generatedEvents.begin()->get()->eventType == capture);
    ASSERT_TRUE(generatedEvents.begin()->get()->getPiece() == pawn);

    ASSERT_TRUE(serviceTable.getPiece(posX, posY) == nullptr);
    ASSERT_TRUE(serviceTable.getPiece(newX, newY) != nullptr);
    ASSERT_TRUE(serviceTable.getPiece(newX, newY)->getX() == newX);
    ASSERT_TRUE(serviceTable.getPiece(newX, newY)->getY() == newY);

    serviceTable.addPiece(std::make_unique<Bishop>(posX, posY, white));
    serviceTable.movePiece(newX, newY, posX, posY);

    ASSERT_TRUE(serviceTable.getPiece(newX, newY) == nullptr);
    ASSERT_TRUE(serviceTable.getPiece(posX, posY) != nullptr);
    ASSERT_TRUE(serviceTable.getPiece(posX, posY)->getX() == posX);
    ASSERT_TRUE(serviceTable.getPiece(posX, posY)->getY() == posY);
}

TEST(tableMovePiece, pawnPromotion) {
    int tableSize = 10;
    int posX = 2;
    int posY = tableSize - 1;
    int newX = 2;
    int newY = tableSize;

    colors color = black;
    colors anotherColor = white;
    std::unique_ptr<Table> table = std::make_unique<Table>(tableSize);
    ServiceTable serviceTable{table, color};

    std::shared_ptr < Pawn > pawn = std::make_unique<Pawn>(Pawn(posX, posY, color));
    serviceTable.addPiece(pawn);

    auto generatedEvents = serviceTable.movePiece(posX, posY, newX, newY);
    ASSERT_TRUE(generatedEvents.size() == 1);
    ASSERT_TRUE(generatedEvents.begin()->get()->eventType == pawn_promotion);
    ASSERT_TRUE(generatedEvents.begin()->get()->getPiece() == pawn);

}