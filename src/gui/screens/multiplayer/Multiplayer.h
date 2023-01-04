// Created by Catalin
#pragma once
#include "../Screen.h"
#include "../../components/chess_table/ChessTable.h"
#include "../../../game/Game.h"

class Multiplayer: public Screen {
private:
    std::string gameState;
    ChessTable chessTable;
    std::unique_ptr<Game> game; //TODO: client/server constructors
};
