// Created by Catalin
#pragma once
#include "../Game.h"
#include "../../gui/components/chess_table/ChessTable.h"

class SinglePlayerGame: public Game {
public:
    explicit SinglePlayerGame(const colors &playerColor);
};
