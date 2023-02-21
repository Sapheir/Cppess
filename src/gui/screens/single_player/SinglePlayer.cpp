// Created by Catalin
#include "SinglePlayer.h"

SinglePlayer::SinglePlayer(sf::RenderWindow &window, sf::Font &font, const unsigned int &fontSize, screens &nextScreen, colors &playerColor)
            : Screen{window, font, fontSize, nextScreen}, chessTable{window.getSize().x, window.getSize().y, playerColor == black}, game{playerColor} {
    chessTable.setPieces(game.getCurrentPiecesInfo());
}

void SinglePlayer::draw() {
    chessTable.setPieces(game.getCurrentPiecesInfo());
    window.draw(chessTable);
    for (const auto &hovered: availablePositions) {
        window.draw(hovered);
    }
}

void SinglePlayer::resize(const unsigned int &width, const unsigned int &height) {
    sf::FloatRect visibleArea{0, 0, (float)width, (float)height};
    window.setView(sf::View{visibleArea});
    chessTable.resize(width, height);
}

void SinglePlayer::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        if (!isSelectedPiece) {
            nextScreen = single_player_options;
        } else {
            availablePositions.clear();
        }
    } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        auto [posX, posY] = chessTable.getClickedTile(event.mouseButton.x, event.mouseButton.y);
        if (!isSelectedPiece) {
            colorAvailablePositions(posX, posY);
        } else {
            tryMoveToPosition(posX, posY);
        }
    }
}

void SinglePlayer::colorAvailablePositions(int posX, int posY) {
    auto positions = game.availableMovesDestinations(posX, posY);
    if (positions.empty()) {
        return;
    }
    isSelectedPiece = true;
    selectedPiecePos = {posX, posY};
    availablePositions.clear();
    auto [pieceSizeX, pieceSizeY] = chessTable.getPieceSize();
    for (const auto &[availablePosX, availablePosY]: positions) {
        auto [boardX, boardY] = chessTable.getBoardPosition(availablePosX, availablePosY);
        sf::RectangleShape hoverPosition{sf::Vector2f{pieceSizeX, pieceSizeY}};
        hoverPosition.setFillColor(sf::Color(0, 0, 255, 50));
        hoverPosition.setPosition(boardX, boardY);
        availablePositions.push_back(hoverPosition);
    }
}

void SinglePlayer::tryMoveToPosition(int posX, int posY) {
    try {
        if (game.isMyTurn())
            game.movePlayerPiece(selectedPiecePos.first, selectedPiecePos.second, posX, posY);
        else
            game.moveOpponentPiece(selectedPiecePos.first, selectedPiecePos.second, posX, posY);
    } catch (std::exception &exception) {
        std::cerr << exception.what() << "\n";
    }
    isSelectedPiece = false;
    availablePositions.clear();
}
