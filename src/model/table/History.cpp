//
// Created by User on 23/12/2022.
//

#include "History.h"
#include "../domain/pieces/bishop/Bishop.h"

void History::addMove(const std::shared_ptr < HistoryMove > &move) {
    this->moves.push_back(std::make_unique<HistoryMove>(1,1,1,1, std::make_unique<Bishop>(2,2,black)));
}

std::shared_ptr < HistoryMove > History::getLastMove() {
    return moves.back();
}
