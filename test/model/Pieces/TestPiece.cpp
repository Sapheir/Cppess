//
// Created by Turca Vasile
//

#include <gtest/gtest.h>
#include <memory>

#include "model/pieces/bishop/Bishop.h"
#include "model/pieces/king/King.h"
#include "model/pieces/knight/Knight.h"
#include "model/pieces/pawn/Pawn.h"
#include "model/pieces/queen/Queen.h"
#include "model/pieces/rook/Rook.h"

TEST(Piece, bishop){
    std::unique_ptr<Piece> piece = std::make_unique<Bishop>(5,5, black);
    Bishop bishop{5,5, black};

    auto pieceMoves = piece->nextPositions(10);
    auto bishopMoves = bishop.nextPositions(10);

    ASSERT_TRUE(pieceMoves.size() == bishopMoves.size());
    for(int i = black ; i < pieceMoves.size() ; i++)
        ASSERT_TRUE(pieceMoves[i] == bishopMoves[i]);
}

TEST(Piece, king) {
    std::unique_ptr<Piece> piece = std::make_unique<King>(5,5,black);
    King king{5,5,black};

    auto pieceMoves = piece->nextPositions(10);
    auto kingMoves = king.nextPositions(10);

    ASSERT_TRUE(pieceMoves.size() == kingMoves.size());
    for(int i = black ; i < pieceMoves.size() ; i++)
        ASSERT_TRUE(pieceMoves[i] == kingMoves[i]);
}

TEST(Piece, knight) {
    std::unique_ptr<Piece> piece = std::make_unique<Knight>(5,5,black);
    Knight knight{5,5,black};

    auto pieceMoves = piece->nextPositions(10);
    auto knightMoves = knight.nextPositions(10);

    ASSERT_TRUE(pieceMoves.size() == knightMoves.size());
    for(int i = black ; i < pieceMoves.size() ; i++)
        ASSERT_TRUE(pieceMoves[i] == knightMoves[i]);
}

TEST(Piece, pawn) {
    std::unique_ptr<Piece> piece = std::make_unique<Pawn>(5,5,black);
    Pawn pawn{5,5,black};

    auto pieceMoves = piece->nextPositions(10);
    auto pawnMoves = pawn.nextPositions(10);

    ASSERT_TRUE(pieceMoves.size() == pawnMoves.size());
    for(int i = black ; i < pieceMoves.size() ; i++)
        ASSERT_TRUE(pieceMoves[i] == pawnMoves[i]);
}

TEST(Piece, queen) {
    std::unique_ptr<Piece> piece = std::make_unique<Queen>(5,5,black);
    Queen queen{5,5,black};

    auto pieceMoves = piece->nextPositions(10);
    auto queenMoves = queen.nextPositions(10);

    ASSERT_TRUE(pieceMoves.size() == queenMoves.size());
    for(int i = black ; i < pieceMoves.size() ; i++)
        ASSERT_TRUE(pieceMoves[i] == queenMoves[i]);
}

TEST(Piece, rook) {
    std::unique_ptr<Piece> piece = std::make_unique<Rook>(5,5,black);
    Rook rook{5,5,black};

    auto pieceMoves = piece->nextPositions(10);
    auto rookMoves = rook.nextPositions(10);

    ASSERT_TRUE(pieceMoves.size() == rookMoves.size());
    for(int i = black ; i < pieceMoves.size() ; i++)
        ASSERT_TRUE(pieceMoves[i] == rookMoves[i]);
}