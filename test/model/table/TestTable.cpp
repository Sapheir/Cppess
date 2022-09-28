//
// Created by Turca Vasile on 27/09/2022.
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


TEST(table, emptyTable) {
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
    std::unique_ptr<Piece> piece2 = table->getPiece(posX, posY);
    ASSERT_TRUE(piece2->getX() == posX);
    ASSERT_TRUE(piece2->getY() == posY);

    ASSERT_TRUE(pieceAddress == piece2.get());
}

TEST(table, addBishopOnTable) {
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    checkPieceOnTable(std::make_unique<Bishop>(posX, posY), tableSize);
}

TEST(table, addKingOnTable) {
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    checkPieceOnTable(std::make_unique<King>(posX, posY), tableSize);
}

TEST(table, addKnightOnTable) {
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    checkPieceOnTable(std::make_unique<Knight>(posX, posY), tableSize);
}

TEST(table, addPawnOnTable) {
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    checkPieceOnTable(std::make_unique<Pawn>(posX, posY), tableSize);
}

TEST(table, addQueenOnTable) {
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    checkPieceOnTable(std::make_unique<Queen>(posX, posY), tableSize);
}

TEST(table, addRookOnTable) {
    int posX = 5;
    int posY = 5;
    int tableSize = 10;
    checkPieceOnTable(std::make_unique<Rook>(posX, posY), tableSize);
}
