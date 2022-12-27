//
// Created by User on 18/12/2022.
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
    colors anotherColor = white;
    std::unique_ptr<Table> table = std::make_unique<Table>(tableSize);
    ServiceTable serviceTable{table, color, anotherColor};

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

    serviceTable.addPiece(std::make_unique<Bishop>(posX + 1, posY + 1, white));
    serviceTable.movePiece(posX + 1, posY + 1, posX, posY);

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
    ServiceTable serviceTable{table, color, anotherColor};

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
    ASSERT_TRUE(generatedEvents.begin()->get()->getEventType() == capture);
    ASSERT_TRUE(generatedEvents.begin()->get()->getPiece() == pawn);

    ASSERT_TRUE(serviceTable.getPiece(posX, posY) == nullptr);
    ASSERT_TRUE(serviceTable.getPiece(newX, newY) != nullptr);
    ASSERT_TRUE(serviceTable.getPiece(newX, newY)->getX() == newX);
    ASSERT_TRUE(serviceTable.getPiece(newX, newY)->getY() == newY);

    serviceTable.addPiece(std::make_unique<Bishop>(posX + 1, posY + 1, white));
    serviceTable.movePiece(posX + 1, posY + 1, posX, posY);
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
    ServiceTable serviceTable{table, color, anotherColor};

    std::shared_ptr < Pawn > pawn = std::make_unique<Pawn>(Pawn(posX, posY, color));
    serviceTable.addPiece(pawn);

    auto generatedEvents = serviceTable.movePiece(posX, posY, newX, newY);
    ASSERT_TRUE(generatedEvents.size() == 1);
    ASSERT_TRUE(generatedEvents.begin()->get()->getEventType() == pawn_promotion);
    ASSERT_TRUE(generatedEvents.begin()->get()->getPiece() == pawn);
}

TEST(tableMovePiece, enPassant) {
    int tableSize = 10;
    int posX = 3;
    int posY = 3;
    int newX = 3;
    int newY = 4;

    colors color = black;
    colors anotherColor = white;
    std::unique_ptr<Table> table = std::make_unique<Table>(tableSize);
    ServiceTable serviceTable{table, color, anotherColor};

    std::shared_ptr < Pawn > pawn = std::make_unique<Pawn>(Pawn(posX, posY, color));
    serviceTable.addPiece(pawn);
    serviceTable.movePiece(posX, posY, newX, newY);

    std::shared_ptr < Pawn > pawn2 = std::make_unique<Pawn>(Pawn(newX, newY + 1, anotherColor));
    serviceTable.addPiece(pawn2);
    serviceTable.movePiece(3, 5, 4, 4);
    ASSERT_TRUE(serviceTable.getLastMoveFromHistory()->getGeneratedEvents().begin()->get()->getEventType() == en_passant);
}

TEST(testMovePiece, kingUnprotected){
    int kingX = 3;
    int kingY = 3;
    int bishopX = 3;
    int bishopY = 4;
    int queenX = 3;
    int queenY = 5;
    int tableSize = 10;

    colors color = black;
    colors anotherColor = white;
    std::unique_ptr<Table> table = std::make_unique<Table>(tableSize);
    ServiceTable serviceTable{table, color, anotherColor};

    serviceTable.addPiece(std::make_unique < King > (kingX, kingY, color));
    serviceTable.addPiece(std::make_unique<Bishop>(bishopX, bishopY, color));
    serviceTable.addPiece(std::make_unique<Queen>(queenX, queenY, anotherColor));

    try{
        serviceTable.movePiece(bishopX, bishopY, bishopX + 1, bishopY + 1);
    }catch(std::string &error){
        ASSERT_TRUE(error.find("The move is not available because you left the king without guard"));
    }
}

TEST(testMovePiece, king_under_attack){
    int kingX = 3;
    int kingY = 3;
    int bishopX = 3;
    int bishopY = 4;
    int queenX = 3;
    int queenY = 5;
    int tableSize = 10;

    colors color = black;
    colors anotherColor = white;
    std::unique_ptr<Table> table = std::make_unique<Table>(tableSize);
    ServiceTable serviceTable{table, color, anotherColor};

    serviceTable.addPiece(std::make_unique < King > (kingX, kingY, color));
    serviceTable.addPiece(std::make_unique<Bishop>(bishopX, bishopY, anotherColor));
    serviceTable.addPiece(std::make_unique<Queen>(queenX, queenY, anotherColor));


    try {
        serviceTable.movePiece(kingX, kingY, kingX, kingY - 1);
        auto it = serviceTable.movePiece(bishopX, bishopY, bishopX + 1, bishopY + 1);

        auto historyRegister = serviceTable.getLastMoveFromHistory();
        ASSERT_TRUE(historyRegister.get()->getGeneratedEvents().begin()->get()->getEventType() == king_under_attack);
    }catch (std::string error){
        std::cout << error;
    }

}