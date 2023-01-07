// Created by Catalin
#include "MultiplayerClient.h"

MultiplayerClient::MultiplayerClient(sf::RenderWindow &window, sf::Font &font, const unsigned int &fontSize, screens &nextScreen, settings &settings)
                 : Screen{window, font, fontSize, nextScreen}, chessTable{window.getSize().x, window.getSize().y, settings.color == black},
                   ioContext{}, game{ioContext, settings.joinString, settings.color} {
    chessTable.setPieces(game.getCurrentPiecesInfo());
}

void MultiplayerClient::draw() {

}

void MultiplayerClient::resize(const unsigned int &width, const unsigned int &height) {

}

void MultiplayerClient::handleEvent(sf::Event &event) {

}

void MultiplayerClient::colorAvailablePositions(int posX, int posY) {

}

void MultiplayerClient::tryMoveToPosition(int posX, int posY) {

}
