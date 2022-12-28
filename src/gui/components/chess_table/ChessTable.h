// Created by Catalin
#pragma once
#include <SFML/Graphics.hpp>
#define PIECE_SIZE 60
#define BOARD_SIZE 480

class ChessTable: public sf::Drawable, public sf::Transformable {
private:
    sf::Texture boardTexture, piecesTexture;
    sf::Sprite board;
    sf::Sprite blackPawnSprite, blackRookSprite, blackBishopSprite, blackKnightSprite, blackKingSprite, blackQueenSprite;
    sf::Sprite whitePawnSprite, whiteRookSprite, whiteBishopSprite, whiteKnightSprite, whiteKingSprite, whiteQueenSprite;
    bool isPieceSelected{};
    std::vector<sf::Sprite> pieces;

    void loadTextures();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    ChessTable(const float &boardTopLeft, const float &boardTopRight);
    void resize(const float &scaleX, const float &scaleY);
    void setPieces();
};
