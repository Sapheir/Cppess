//
// Created by Turca Vasile on 27/09/2022.
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


TEST(tableAddGet, emptyTable) {
    const int tableSize = 10;
    auto table = std::make_unique<Table>(tableSize);

    /* Check if the size of the table is correctly configured */
    ASSERT_TRUE(table->getTableSize() == tableSize);
}

bool pairCompareEq(const std::pair < int, int > X, const std::pair < int, int > Y) {
    return (X.first == Y.first && X.second == Y.second);
}

void sortAll2PairVectors(std::vector < std::pair < int, int > > &firstVector,
                         std::vector < std::pair < int, int > > &secondVector){
    sort(firstVector.begin(), firstVector.end());
    sort(secondVector.begin(), secondVector.end());
}

void comparePairVectors(std::vector < std::pair < int, int > > &firstVector,
                        std::vector < std::pair < int, int > > &secondVector){

    /* First check if the vectors have same size*/
    ASSERT_TRUE(firstVector.size() == secondVector.size());

    sortAll2PairVectors(firstVector, secondVector);
    for(int index = 0 ; index < firstVector.size() ; index++)
        ASSERT_TRUE(pairCompareEq(firstVector[index], secondVector[index]));

}

void comparePieces(std::unique_ptr<Piece> piece1, std::unique_ptr<Piece> piece2, const int &tableSize){
    /* Check if the possible moves are identical to moves of a Bishop with (posX, posY) */
    auto piece1NextPositions = piece1->nextPositions(tableSize);
    auto piece2NextPositions =  piece2->nextPositions(tableSize);

    comparePairVectors(piece1NextPositions, piece2NextPositions);
}

void checkPieceOnTable(std::unique_ptr < Piece > piece, const int &tableSize){
    int posX = piece->getX();
    int posY = piece->getY();
    auto table = std::make_unique<Table>(tableSize);

    /* Check if the size of the table is correctly configured */
    ASSERT_TRUE(table->getTableSize() == tableSize);

    Piece* pieceAddress = piece.get();
    table->addPiece( std::move(piece));

    /* Check if the size of the table is correctly configured */
    ASSERT_TRUE(table->getTableSize() == tableSize);

    /* Check if the piece from (posX, posY) is our piece */
    std::shared_ptr<Piece> piece2 = table->getPiece(posX, posY);
    ASSERT_TRUE(piece2->getX() == posX);
    ASSERT_TRUE(piece2->getY() == posY);

    ASSERT_TRUE(pieceAddress == piece2.get());
}

TEST(tableAddGet, addBishopOnTable) {
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    colors color = black;
    checkPieceOnTable(std::make_unique<Bishop>(posX, posY, color), tableSize);
}

TEST(tableAddGet, addKingOnTable) {
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    colors color = black;
    checkPieceOnTable(std::make_unique<King>(posX, posY, color), tableSize);
}

TEST(tableAddGet, addKnightOnTable) {
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    colors color = black;
    checkPieceOnTable(std::make_unique<Knight>(posX, posY, color), tableSize);
}

TEST(tableAddGet, addPawnOnTable) {
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    colors color = black;
    checkPieceOnTable(std::make_unique<Pawn>(posX, posY, color), tableSize);
}

TEST(tableAddGet, addQueenOnTable) {
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    colors color = black;
    checkPieceOnTable(std::make_unique<Queen>(posX, posY, color), tableSize);
}

TEST(tableAddGet, addRookOnTable) {
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    colors color = black;
    checkPieceOnTable(std::make_unique<Rook>(posX, posY, color), tableSize);
}
