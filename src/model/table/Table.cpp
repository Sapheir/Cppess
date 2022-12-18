//
// Created by Turca Vasile
//

#include <algorithm>
#include "Table.h"

Table::Table(int tableSize) {
    this->tableSize = tableSize;
}

int Table::getTableSize() const {
    return tableSize;
}

void Table::addPiece(std::shared_ptr<Piece> newPiece) {
    tableContent.push_back(std::move(newPiece));
}

std::shared_ptr<Piece> Table::getPiece(const int &posX, const int &posY) {
    for(auto &it: tableContent)
        if(it->sameCoordinates(posX, posY))
            return it;
    return {nullptr};
}

std::shared_ptr<Piece> Table::removePiece(const int &posX, const int &posY) {
    for(auto &it : tableContent)
        if(it->sameCoordinates(posX, posY)){
            auto iterator = std::find(tableContent.begin(), tableContent.end(), it);
            std::shared_ptr<Piece> piece = it;
            tableContent.erase(iterator);
            return piece;
        }
    return {nullptr};
}
