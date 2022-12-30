// Created by Catalin
#include <iostream>
#include "ChessTable.h"

ChessTable::ChessTable(const unsigned int &windowWidth, const unsigned int &windowHeight,  const bool &isRotated)
          : pieceSizeX{PIECE_SIZE}, pieceSizeY{PIECE_SIZE}, isRotated{isRotated} {
    loadTextures();
    resize(windowWidth, windowHeight);
}

void ChessTable::loadTextures() {
    if (!boardTexture.loadFromFile("../assets/board.png")) {
        throw std::runtime_error("Board image was not found!");
    }
    board.setTexture(boardTexture);
    if (!piecesTexture.loadFromFile("../assets/pieces.png")) {
        throw std::runtime_error("Pieces image was not found!");
    }

    blackQueenSprite.setTexture(piecesTexture);
    blackQueenSprite.setTextureRect(sf::IntRect{0, 0, PIECE_SIZE, PIECE_SIZE});

    whiteQueenSprite.setTexture(piecesTexture);
    whiteQueenSprite.setTextureRect(sf::IntRect{0, PIECE_SIZE, PIECE_SIZE, PIECE_SIZE});

    blackKingSprite.setTexture(piecesTexture);
    blackKingSprite.setTextureRect(sf::IntRect{PIECE_SIZE, 0, PIECE_SIZE, PIECE_SIZE});

    whiteKingSprite.setTexture(piecesTexture);
    whiteKingSprite.setTextureRect(sf::IntRect{PIECE_SIZE, PIECE_SIZE, PIECE_SIZE, PIECE_SIZE});

    blackRookSprite.setTexture(piecesTexture);
    blackRookSprite.setTextureRect(sf::IntRect{2*PIECE_SIZE, 0, PIECE_SIZE, PIECE_SIZE});

    whiteRookSprite.setTexture(piecesTexture);
    whiteRookSprite.setTextureRect(sf::IntRect{2*PIECE_SIZE, PIECE_SIZE, PIECE_SIZE, PIECE_SIZE});

    blackKnightSprite.setTexture(piecesTexture);
    blackKnightSprite.setTextureRect(sf::IntRect{3*PIECE_SIZE, 0, PIECE_SIZE, PIECE_SIZE});

    whiteKnightSprite.setTexture(piecesTexture);
    whiteKnightSprite.setTextureRect(sf::IntRect{3*PIECE_SIZE, PIECE_SIZE, PIECE_SIZE, PIECE_SIZE});

    blackBishopSprite.setTexture(piecesTexture);
    blackBishopSprite.setTextureRect(sf::IntRect{4*PIECE_SIZE, 0, PIECE_SIZE, PIECE_SIZE});

    whiteBishopSprite.setTexture(piecesTexture);
    whiteBishopSprite.setTextureRect(sf::IntRect{4*PIECE_SIZE, PIECE_SIZE, PIECE_SIZE, PIECE_SIZE});

    blackPawnSprite.setTexture(piecesTexture);
    blackPawnSprite.setTextureRect(sf::IntRect{5*PIECE_SIZE, 0, PIECE_SIZE, PIECE_SIZE});

    whitePawnSprite.setTexture(piecesTexture);
    whitePawnSprite.setTextureRect(sf::IntRect{5*PIECE_SIZE, PIECE_SIZE, PIECE_SIZE, PIECE_SIZE});
}

void ChessTable::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(board, states);
    for (const auto &piece: pieces) {
        target.draw(piece, states);
    }
}

void ChessTable::resize(const unsigned int &newWidth, const unsigned int &newHeight) {
    float scaleX = (float)newWidth / BOARD_SIZE, scaleY = (float)newHeight / BOARD_SIZE;
    pieceSizeX = (float) scaleX * PIECE_SIZE;
    pieceSizeY = (float) scaleY * PIECE_SIZE;
    board.setScale(scaleX, scaleY);
}

void ChessTable::setPieces(const std::vector<piece_info> &piecesInfo) {
    pieces.clear();
    for (const auto &pieceInfo: piecesInfo) {
        auto [posX, posY] = getBoardPosition(pieceInfo.posX, pieceInfo.posY);
        posX--;
        posY--;
        bool isWhite = pieceInfo.color == white;
        switch (pieceInfo.piece_type) {
            case rook:
                pieces.push_back(makePiece(isWhite ? whiteRookSprite : blackRookSprite, posX, posY));
                break;
            case knight:
                pieces.push_back(makePiece(isWhite ? whiteKnightSprite : blackKnightSprite, posX, posY));
                break;
            case bishop:
                pieces.push_back(makePiece(isWhite ? whiteBishopSprite : blackBishopSprite, posX, posY));
                break;
            case queen:
                pieces.push_back(makePiece(isWhite ? whiteQueenSprite : blackQueenSprite, posX, posY));
                break;
            case king:
                pieces.push_back(makePiece(isWhite ? whiteKingSprite : blackKingSprite, posX, posY));
                break;
            case pawn:
                pieces.push_back(makePiece(isWhite ? whitePawnSprite : blackPawnSprite, posX, posY));
                break;
            default:
                break;
        }
    }
}

sf::Sprite ChessTable::makePiece(const sf::Sprite &pieceSprite, float posX, float posY) const {
    sf::Sprite piece{pieceSprite};
    piece.setPosition(posX, posY);
    float scaleX = (float) pieceSizeX / PIECE_SIZE, scaleY = (float) pieceSizeY / PIECE_SIZE;
    piece.setScale(scaleX, scaleY);
    return piece;
}

std::pair<float, float> ChessTable::getBoardPosition(int posX, int posY) const {
    float boardX, boardY;
    if (!isRotated) {
        boardX = (float) posX * pieceSizeX;
        boardY = (float) posY * pieceSizeY;
    } else {
        boardX = (float) posX * pieceSizeX;
        boardY = (float) (7 - posY) * pieceSizeY;
    }
    return {boardX, boardY};
}

std::pair<int, int> ChessTable::getClickedTile(int mouseX, int mouseY) const {
    int posX, posY;
    if (!isRotated) {
        posX = mouseX / (int)pieceSizeX;
        posY = mouseY / (int)pieceSizeY;
    } else {
        posX = mouseX / (int)pieceSizeX;
        posY = 7 - mouseY / (int)pieceSizeY;
    }
    return {posX, posY};
}

std::pair<float, float> ChessTable::getPieceSize() {
    return {pieceSizeX, pieceSizeY};
}
