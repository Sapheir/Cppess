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
    bool isSelectedPiece{};
    std::pair<int, int> selectedPiecePos;
    std::vector<sf::RectangleShape> availablePositions;

    void colorAvailablePositions(int posX, int posY);
    void tryMoveToPosition(int posX, int posY);

public:
    SinglePlayer(sf::RenderWindow& window, sf::Font& font, const unsigned int &fontSize, screens &nextScreen, colors &playerColor);
    void draw() override;
    void resize(const unsigned int &width, const unsigned int &height) override;
    void handleEvent(sf::Event &event) override;
};
