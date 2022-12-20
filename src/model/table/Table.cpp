//
// Created by Turca Vasile
//

#include <algorithm>
#include <iostream>
#include "Table.h"

Table::Table(int tableSize) {
    this->tableSize = tableSize;
}

int Table::getTableSize() const {
    return tableSize;
}

void Table::addPiece(const std::shared_ptr<Piece>& newPiece) {
    tableContent[{newPiece->getX(), newPiece->getY()}] = newPiece;
}

std::shared_ptr<Piece> Table::getPiece(const int &posX, const int &posY) const {
    auto it = tableContent.find({posX, posY});
    if(it != tableContent.end())
        return it->second;
    return {nullptr};
}

std::shared_ptr<Piece> Table::removePiece(const int &posX, const int &posY) {
    auto it = tableContent.find({posX, posY});
    if(it != tableContent.end()){
        auto piece = it->second;
        tableContent.erase(it);
        return piece;
    }
    return {nullptr};
}

void Table::movePiece(int x, int y, int newX, int newY){
    std::shared_ptr<Piece> piece = this->getPiece(x, y);
    if (piece == nullptr) {
        std::string errorMessage = "There is no piece on chosen position! ";
        throw errorMessage;
    }

    auto destinations = this->availableMovesDestinations(piece);

    if(std::find(destinations.begin(), destinations.end(), std::make_pair(newX, newY))== destinations.end()) {
        std::string errorMessage = "The move is not available! ";
        throw errorMessage;
    }

    movePieceOnValidDestination(piece, newX, newY);
}

std::vector<std::pair<int, int> > Table::availableMovesDestinations(const std::shared_ptr<Piece> &piece) const {
    if(piece == nullptr)
        return {};

    if(piece->isKnight())
        return availableMovesDestinationsKnight(piece);
    return availableMovesDestinationsNonKnight(piece);
}

std::vector<std::pair<int, int> > Table::availableMovesDestinations(const int &posX, const int &posY) const {
    std::shared_ptr < Piece > piece = this->getPiece(posX, posY);
    return this->availableMovesDestinations(piece);
}

std::vector<std::pair<int, int> > Table::availableMovesDestinationsKnight(const std::shared_ptr<Piece> &piece) const {
    auto destinations = piece->nextPositions(this->tableSize);
    std::vector < std::pair < int, int > > availableNextMoves;
    for(auto destination: destinations) {
        if (getPiece(destination.first, destination.second)->sameColor(piece))
            continue;
        if (tableContent.find(destination) == tableContent.end())
            availableNextMoves.push_back(destination);
    }
    return availableNextMoves;
}

std::vector<std::pair<int, int> > Table::availableMovesDestinationsNonKnight(const std::shared_ptr<Piece> &piece) const {
    auto destinations = piece->nextPositions(this->tableSize);
    std::vector < std::pair < int, int > > availableDestinations;
    for(auto destination: destinations) {
        if(piece->sameColor(getPiece(destination.first, destination.second)))
            continue;
        if (noPieceBetween(piece->getX(), piece->getY(), destination.first, destination.second))
            availableDestinations.push_back(destination);
    }

    return availableDestinations;
}

bool Table::noPieceBetween(int x1, int y1, int x2, int y2) const {
    int scaleX = (x2 - x1) / abs(x2 - x1);
    int scaleY = (y2 - y1) / abs(y2 - y1);

    for(int x = x1 ; x <= x2 ; x += scaleX)
        for(int y = y1 ; y <= y2 ; y += scaleY) {
            if(x == x1 && y == y1) continue;
            if(x == x2 && y == y2) continue;
            if (getPiece(x, y) != nullptr)
                return false;
        }
    return true;
}

void Table::movePieceOnValidDestination(std::shared_ptr<Piece> piece, int newX, int newY) {
    this->tableContent.erase({piece->getX(), piece->getY()});
    this->tableContent[{newX, newY}] = piece;
    piece->setX(newX);
    piece->setY(newY);
}
