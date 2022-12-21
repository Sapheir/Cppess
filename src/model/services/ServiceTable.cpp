//
// Created by Turca Vasile
//

#include "ServiceTable.h"

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

std::vector < std::shared_ptr < BaseEvent > > ServiceTable::movePiece(const int &x, const int &y,
                                                                      const int &newX, const int &newY){
    std::shared_ptr<Piece> piece = table->getPiece(x, y);

    if (piece == nullptr) {
        std::string errorMessage = "There is no piece on the chosen position! ";
        throw errorMessage;
    }

    if(piece->getColor() != currentPlayer){
        std:: string errorMessage = "You cannot move the pieces of the opponent! ";
        throw errorMessage;
    }

    auto destinations = table->availableMovesDestinations(piece);

    if(std::find(destinations.begin(), destinations.end(), std::make_pair(newX, newY))== destinations.end()) {
        std::string errorMessage = "The move is not available! ";
        throw errorMessage;
    }

    auto events = getSpecialEvents(piece, newX, newY);

    table->movePieceOnValidDestination(piece, newX, newY);
    this->changeTurn();

    return events;
}

std::vector < std::shared_ptr < BaseEvent > > ServiceTable::getSpecialEvents(std::shared_ptr < Piece > &piece,
                                                                             const int &newX, const int &newY){
    std::vector < std::shared_ptr < BaseEvent > > events;

    if(checkPawnPromotion(piece, newX, newY))
        events.push_back(std::make_unique<PawnPromotion>(piece));

    /* check if there is a piece of the opponent captured during the move of the current piece */
    std::shared_ptr < Piece > removedPiece = table->removePiece(newX, newY);
    if(removedPiece != nullptr)
        events.push_back(std::make_unique<CapturedPiece>(removedPiece));



    return events;
}

bool ServiceTable::checkPawnPromotion(std::shared_ptr<Piece> &piece, const int &newX, const int &newY) const{
    if(!piece->isPawn()) return false;
    if(!table->pieceWillBeOnOppositeEdge(newX, newY)) return false;
    return true;
}

bool ServiceTable::checkEnPassant(std::shared_ptr<Piece> &piece, const int &newX, const int &newY) const {

}

void ServiceTable::changeTurn() {
    if(currentPlayer == firstPlayerColor)
        currentPlayer = secondPlayerColor;
    else
        currentPlayer = firstPlayerColor;
}
