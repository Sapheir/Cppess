//
// Created by Turca Vasile
//

#include "Table.h"

Table::Table(int tableSize) {
    this->tableSize = tableSize;
}

int Table::getTableSize() const {
    return tableSize;
}

void Table::addPiece(std::unique_ptr<Piece> newPiece) {
    tableContent.push_back(std::move(newPiece));
}

std::unique_ptr<Piece> Table::getPiece(const int &posX, const int &posY) {
    for(auto &it: tableContent)
        if(it->getX() == posX && it->getY() == posY)
            return std::move(it);
};