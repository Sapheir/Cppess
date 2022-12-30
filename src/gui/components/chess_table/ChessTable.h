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
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    ChessTable(const unsigned int &windowWidth, const unsigned int &windowHeight, const bool &isRotated);

    /**
     * Used to resize the chess table
     * @param newWidth width to resize chess table to
     * @param newHeight height to resize chess table to
     */
    void resize(const unsigned int &newWidth, const unsigned int &newHeight);

    /**
     * Set the pieces visually on the table
     * @param piecesInfo information about the pieces to draw on the table
     */
    void setPieces(const std::vector<piece_info> &piecesInfo);

    /**
     * @param mouseX X coordinate of the mouse click
     * @param mouseY Y coordinate of the mouse click
     * @return the position of the clicked tile
     */
    std::pair<int, int> getClickedTile(int mouseX, int mouseY) const;

    /**
     * @param posX X coordinate of the tile
     * @param posY Y coordinate of the tile
     * @return actual position of the tile on the board
     */
    std::pair<float, float> getBoardPosition(int posX, int posY) const;

    /**
     * @return size of a piece/tile on the board
     */
    std::pair<float, float> getPieceSize();
};
