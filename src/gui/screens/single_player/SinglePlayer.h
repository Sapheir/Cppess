// Created by Catalin
#pragma once
#include "../Screen.h"
#include "../../../model/domain/pieces/colors.h"
#include "../../components/chess_table/ChessTable.h"
#include "../../../game/single_player/SinglePlayerGame.h"

class SinglePlayer: public Screen {
private:
    std::string gameState;
    ChessTable chessTable;
    SinglePlayerGame game;

public:
    SinglePlayer(sf::RenderWindow& window, sf::Font& font, const unsigned int &fontSize, screens &nextScreen, colors &playerColor);
    void draw() override;
    void resize(const unsigned int &width, const unsigned int &height) override;
    void handleEvent(sf::Event &event) override;
};
