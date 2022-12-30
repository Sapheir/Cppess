// Created by Catalin
#pragma once
#include "colors.h"

enum piece_types {
    rook,
    knight,
    bishop,
    queen,
    king,
    pawn
};

struct piece_info {
    piece_types piece_type;
    int posX, posY;
    colors color;
};
