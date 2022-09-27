//
// Created by User on 27/09/2022.
//

#include <gtest/gtest.h>

#include "model/pieces/bishop/Bishop.h"
#include "model/pieces/king/King.h"
#include "model/pieces/knight/Knight.h"
#include "model/pieces/pawn/Pawn.h"
#include "model/pieces/queen/Queen.h"
#include "model/pieces/rook/Rook.h"

TEST(Piece, bishop){
    Piece* piece = new Bishop{5, 5};
    Bishop bishop{5,5};

    auto pieceMoves = piece->nextPositions(10);
    auto bishopMoves = bishop.nextPositions(10);

    ASSERT_TRUE(pieceMoves.size() == bishopMoves.size());
    for(int i = 0 ; i < pieceMoves.size() ; i++)
        ASSERT_TRUE(pieceMoves[i] == bishopMoves[i]);
}

TEST(Piece, king){
    Piece* piece = new King{5, 5};
    King king{5,5};

    auto pieceMoves = piece->nextPositions(10);
    auto kingMoves = king.nextPositions(10);

    ASSERT_TRUE(pieceMoves.size() == kingMoves.size());
    for(int i = 0 ; i < pieceMoves.size() ; i++)
        ASSERT_TRUE(pieceMoves[i] == kingMoves[i]);
}

TEST(Piece, knight){
    Piece* piece = new Knight{5, 5};
    Knight knight{5,5};

    auto pieceMoves = piece->nextPositions(10);
    auto knightMoves = knight.nextPositions(10);

    ASSERT_TRUE(pieceMoves.size() == knightMoves.size());
    for(int i = 0 ; i < pieceMoves.size() ; i++)
        ASSERT_TRUE(pieceMoves[i] == knightMoves[i]);
}

TEST(Piece, pawn){
    Piece* piece = new Pawn{5, 5};
    Pawn pawn{5,5};

    auto pieceMoves = piece->nextPositions(10);
    auto pawnMoves = pawn.nextPositions(10);

    ASSERT_TRUE(pieceMoves.size() == pawnMoves.size());
    for(int i = 0 ; i < pieceMoves.size() ; i++)
        ASSERT_TRUE(pieceMoves[i] == pawnMoves[i]);
}

TEST(Piece, queen){
    Piece* piece = new Queen{5, 5};
    Queen queen{5,5};

    auto pieceMoves = piece->nextPositions(10);
    auto queenMoves = queen.nextPositions(10);

    ASSERT_TRUE(pieceMoves.size() == queenMoves.size());
    for(int i = 0 ; i < pieceMoves.size() ; i++)
        ASSERT_TRUE(pieceMoves[i] == queenMoves[i]);
}

TEST(Piece, rook){
    Piece* piece = new Rook{5, 5};
    Rook rook{5,5};

    auto pieceMoves = piece->nextPositions(10);
    auto rookMoves = rook.nextPositions(10);

    ASSERT_TRUE(pieceMoves.size() == rookMoves.size());
    for(int i = 0 ; i < pieceMoves.size() ; i++)
        ASSERT_TRUE(pieceMoves[i] == rookMoves[i]);
}