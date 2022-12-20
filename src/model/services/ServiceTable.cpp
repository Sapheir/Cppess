//
// Created by Turca Vasile
//

#include "ServiceTable.h"

void ServiceTable::movePiece(int x, int y, int newX, int newY){
    std::shared_ptr<Piece> piece = table->getPiece(x, y);
    if (piece == nullptr) {
        std::string errorMessage = "There is no piece on chosen position! ";
        throw errorMessage;
    }

    auto destinations = table->availableMovesDestinations(piece);

    if(std::find(destinations.begin(), destinations.end(), std::make_pair(newX, newY))== destinations.end()) {
        std::string errorMessage = "The move is not available! ";
        throw errorMessage;
    }

    table->movePieceOnValidDestination(piece, newX, newY);
}


std::shared_ptr<Piece> ServiceTable::getPiece(const int &posX, const int &posY) const {
    return table->getPiece(posX, posY);
}

std::shared_ptr<Piece> ServiceTable::removePiece(const int &posX, const int &posY) {
    table->removePiece(posX, posY);
}

void ServiceTable::addPiece(const std::shared_ptr<Piece> &newPiece) {
    table->addPiece(newPiece);
}

std::vector<std::pair<int, int>> ServiceTable::availableMovesDestinations(const int &posX, const int &posY) const {
    return table->availableMovesDestinations(posX, posY);
}