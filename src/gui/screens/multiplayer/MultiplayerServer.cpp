// Created by Catalin
#include "MultiplayerServer.h"

MultiplayerServer::MultiplayerServer(sf::RenderWindow &window, sf::Font &font, const unsigned int &fontSize, screens &nextScreen, settings &settings)
                 : Screen{window, font, fontSize, nextScreen}, chessTable{window.getSize().x, window.getSize().y, settings.color == black},
                   ioContext{}, game{ioContext, 27007, settings.color} {
    chessTable.setPieces(game.getCurrentPiecesInfo());
}

void MultiplayerServer::draw() {

}

void MultiplayerServer::resize(const unsigned int &width, const unsigned int &height) {

}

void MultiplayerServer::handleEvent(sf::Event &event) {

}

void MultiplayerServer::colorAvailablePositions(int posX, int posY) {

}

void MultiplayerServer::tryMoveToPosition(int posX, int posY) {

}
