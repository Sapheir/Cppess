// Created by Catalin
#pragma once
#include <SFML/Graphics.hpp>
#include "../../../model/domain/pieces/pieces.h"

#define PIECE_SIZE 60
#define BOARD_SIZE 480

class ChessTable: public sf::Drawable, public sf::Transformable {
private:
    sf::Texture boardTexture, piecesTexture;
    sf::Sprite board;
    sf::Sprite blackPawnSprite, blackRookSprite, blackBishopSprite, blackKnightSprite, blackKingSprite, blackQueenSprite;
    sf::Sprite whitePawnSprite, whiteRookSprite, whiteBishopSprite, whiteKnightSprite, whiteKingSprite, whiteQueenSprite;
    bool isPieceSelected{}, isRotated{};
    std::vector<sf::Sprite> pieces;
    float pieceSizeX, pieceSizeY;

    void loadTextures();
    sf::Sprite makePiece(const sf::Sprite &pieceSprite, float posX, float posY) const;
    std::pair<float, float> getBoardPosition(int posX, int posY) const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    ChessTable(const unsigned int &windowWidth, const unsigned int &windowHeight, const bool &isRotated);
    void resize(const unsigned int &newWidth, const unsigned int &newHeight);
    void setPieces(const std::vector<piece_info> &piecesInfo);
};
