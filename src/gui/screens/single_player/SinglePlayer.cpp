// Created by Catalin
#include "SinglePlayer.h"

SinglePlayer::SinglePlayer(sf::RenderWindow &window, sf::Font &font, const unsigned int &fontSize, screens &nextScreen, colors &playerColor)
            : Screen{window, font, fontSize, nextScreen}, chessTable{window.getSize().x, window.getSize().y, playerColor == black}, game{playerColor} {
    chessTable.setPieces(game.getCurrentPiecesInfo());
}

void SinglePlayer::draw() {
    chessTable.setPieces(game.getCurrentPiecesInfo());
    window.draw(chessTable);
}

void SinglePlayer::resize(const unsigned int &width, const unsigned int &height) {
    sf::FloatRect visibleArea{0, 0, (float)width, (float)height};
    window.setView(sf::View{visibleArea});
    chessTable.resize(width, height);
}

void SinglePlayer::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        nextScreen = single_player_options;
    }
}

