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


std::vector<std::pair<int, int> > Table::availableMovesDestinations(const std::shared_ptr<Piece> &piece) const {
    if(piece == nullptr)
        return {};

    if(piece->isKnight())
        return availableMovesDestinationsKnight(piece);
    if(piece->isPawn())
        return availableMovesDestinationsPawn(piece);
    return availableMovesDestinationsNonKnightOrPawn(piece);
}

std::vector<std::pair<int, int> > Table::availableMovesDestinations(const int &posX, const int &posY) const {
    std::shared_ptr < Piece > piece = this->getPiece(posX, posY);
    return this->availableMovesDestinations(piece);
}

std::vector<std::pair<int, int> > Table::availableMovesDestinationsPawn(const std::shared_ptr<Piece> &piece) const {
    auto destinations = piece->nextPositions(this->tableSize);
    std::vector < std::pair < int, int > > availableNextMoves;
    for(auto destination: destinations){
        std::shared_ptr < Piece > destinationPiece = getPiece(destination.first, destination.second);
        if(destinationPiece != nullptr)
            if(destinationPiece->sameColor(piece))
                continue;
        if (tableContent.find(destination) == tableContent.end() ) {
            if (abs(piece->getX() - destination.first) == 0)
                availableNextMoves.push_back(destination);
            else{
                std::shared_ptr < Piece > enPassantPiece = getPiece(piece->getX(), destination.second);
                if(enPassantPiece != nullptr)
                    if(enPassantPiece->isPawn())
                        availableNextMoves.push_back(destination);
            }
        }else {
            if (abs(piece->getX() - destination.first) == 1)
                availableNextMoves.push_back(destination);
        }
    }
    return availableNextMoves;
}

std::vector<std::pair<int, int> > Table::availableMovesDestinationsKnight(const std::shared_ptr<Piece> &piece) const {
    auto destinations = piece->nextPositions(this->tableSize);
    std::vector < std::pair < int, int > > availableNextMoves;
    for(auto destination: destinations) {
        auto pieceAtDestination = getPiece(destination.first, destination.second);
        if (pieceAtDestination && pieceAtDestination->sameColor(piece))
            continue;
        if (tableContent.find(destination) == tableContent.end())
            availableNextMoves.push_back(destination);
    }
    return availableNextMoves;
}

std::vector<std::pair<int, int> > Table::availableMovesDestinationsNonKnightOrPawn(const std::shared_ptr<Piece> &piece) const {
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
    if(x1 == x2){
        for(int y = std::min(y1, y2) + 1 ; y < std::max(y1, y2) ; y++)
            if(getPiece(x1, y) != nullptr)
                return false;
        return true;
    }
    if(y1 == y2){
        for(int x = std::min(x1, x2) + 1 ; x < std::max(x1, x2) ; x++)
            if(getPiece(x, y1) != nullptr)
                return false;
        return true;
    }
    int scaleX = (x2 - x1) / abs(x2 - x1);
    int scaleY = (y2 - y1) / abs(y2 - y1);

    if(abs(scaleX) != abs(scaleY))
        return true;

    if(abs(x2 - x1) == 1 && abs(y2 - y1) == 1)
        return true;

    int addingX = scaleX;
    int addingY = scaleY;
    while(x1 + addingX != x2){
        if(getPiece(x1 + addingX, y1 + addingY))
            return false;
        addingX += scaleX;
        addingY += scaleY;
    }

    return true;
}

void Table::movePieceOnValidDestination(std::shared_ptr<Piece> piece, int newX, int newY) {
    this->tableContent.erase({piece->getX(), piece->getY()});
    this->tableContent[{newX, newY}] = piece;
    piece->setX(newX);
    piece->setY(newY);
    piece->setFirstMove(false);
}

bool Table::pieceWillBeOnOppositeEdge(const int &newX, const int &newY) const {
    return (newY == tableSize);
}

std::shared_ptr<Piece> Table::getKing(colors color) const {
    for(const auto& piece: tableContent) {
        if (piece.second->getColor() != color) continue;
        if (piece.second->isKing())
            return piece.second;
    }
    return nullptr;
}

bool Table::kingUnderAttack(colors color) const{
    std::shared_ptr < Piece > king = this->getKing(color);
    for(const auto &piece: tableContent) {
        if (piece.second->getColor() == color) continue;
        if(!noPieceBetween(king->getX(), king->getY(), piece.second->getX(), piece.second->getY()))
            continue;
        auto pieceDestination = piece.second->nextPositions(tableSize);
        auto possiblePositionWhereAreKingCoordinates = std::find(pieceDestination.begin(), pieceDestination.end(),
                                                               std::make_pair(king->getX(), king->getY()));

        if(possiblePositionWhereAreKingCoordinates != pieceDestination.end()) {
            return true;
        }
    }
    return false;
}

std::vector < std::pair < int, int > >  Table::underAttack(const int &x, const int &y) const {
    std::vector < std::pair < int, int > > attackers;
    for(const auto &it: tableContent) {
        auto destinations = availableMovesDestinations(it.first.first, it.first.second);
        auto position = std::find(destinations.begin(), destinations.end(), std::make_pair(x, y));
        if(position != destinations.end())
            attackers.push_back(it.first);
    }
    return attackers;
}
