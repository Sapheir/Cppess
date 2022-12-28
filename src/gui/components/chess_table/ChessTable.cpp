// Created by Catalin
#include "ChessTable.h"

ChessTable::ChessTable(const float &boardTopLeft, const float &boardTopRight) {
    loadTextures();
    board.setPosition(boardTopLeft, boardTopRight);
    setPieces();
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

void ChessTable::resize(const float &scaleX, const float &scaleY) {
    board.setScale(scaleX, scaleY);
    for (auto &piece: pieces) {
        piece.setScale(scaleX, scaleY);
    }
}

void ChessTable::setPieces() {
}
