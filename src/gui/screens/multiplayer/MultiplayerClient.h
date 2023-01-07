// Created by Catalin
#pragma once
#include "../Screen.h"
#include "../../components/chess_table/ChessTable.h"
#include "../../../game/multiplayer/MultiplayerGameClient.h"

class MultiplayerClient: public Screen {
private:
    std::string gameState;
    ChessTable chessTable;
    MultiplayerGameClient game;
    bool isSelectedPiece{};
    std::pair<int, int> selectedPiecePos;
    std::vector<sf::RectangleShape> availablePositions;
    asio::io_context ioContext;

    void colorAvailablePositions(int posX, int posY);
    void tryMoveToPosition(int posX, int posY);

public:
    MultiplayerClient(sf::RenderWindow& window, sf::Font& font, const unsigned int &fontSize, screens &nextScreen, settings &settings);
    void draw() override;
    void resize(const unsigned int &width, const unsigned int &height) override;
    void handleEvent(sf::Event &event) override;
};
