//
// Created by Turca Vasile
//

#include "ServiceTable.h"
#include "../domain/pieces/pawn/Pawn.h"

std::shared_ptr<Piece> ServiceTable::getPiece(const int &posX, const int &posY) const {
    return table->getPiece(posX, posY);
}

std::shared_ptr<Piece> ServiceTable::removePiece(const int &posX, const int &posY) {
    return table->removePiece(posX, posY);
}

void ServiceTable::addPiece(const std::shared_ptr<Piece> &newPiece) {
    table->addPiece(newPiece);
}

std::vector<std::pair<int, int>> ServiceTable::availableMovesDestinations(const int &posX, const int &posY) const {
    auto piece = this->table->getPiece(posX, posY);
    if(piece == nullptr)
        return {};
    if(piece->getColor() != currentPlayer)
        return {};
    return table->availableMovesDestinations(posX, posY);
}

void ServiceTable::addInHistory(const int &x, const int &y, const int &newX, const int &newY, const std::shared_ptr < Piece > &piece){
    auto events = this->getSpecialEvents(piece, newX, newY);
    std::shared_ptr < HistoryMove > historyMove = std::make_unique<HistoryMove>(x, y, newX, newY, piece);
    for(const auto& event: events)
        historyMove->addGeneratedEvent(event);
    this->history.push_back(historyMove);
}


void ServiceTable::checkMoveAvailable(const int &x, const int &y, const int &newX, const int &newY) const {
    std::shared_ptr<Piece> piece = table->getPiece(x, y);
    if(x == newX && y == newY){
        throw std::runtime_error("The move is not available! ");
    }

    if (piece == nullptr) {
        throw std::runtime_error("There is no piece on the chosen position! ");
    }

    if(piece->getColor() != currentPlayer){
        throw std::runtime_error("You cannot move the pieces of the opponent! ");
    }

    auto destinations = table->availableMovesDestinations(piece);
    if(std::find(destinations.begin(), destinations.end(), std::make_pair(newX, newY))== destinations.end()) {
        throw std::runtime_error("The move is not available! ");
    }
}



std::vector < std::shared_ptr < BaseEvent > > ServiceTable::movePiece(const int &x, const int &y,
                                                                           const int &newX, const int &newY){
    checkMoveAvailable(x, y, newX, newY);
    std::shared_ptr<Piece> piece = table->getPiece(x, y);
    addInHistory(x, y, newX, newY, piece);
    table->movePieceOnValidDestination(piece, newX, newY);
    addOpponentKingUnderAttackInHistory();

    if(piece->isKing()) {
        if (this->kingUnprotected()) {
            throw std::runtime_error("The move is not available because you left the king without guard! ");
        }
    }
    if(piece->isPawn())
        piece->doubleMoveDisable();
    checkGameEnded();
    this->changeTurn();
    return this->getLastMoveFromHistory()->getGeneratedEvents();
}

std::vector < std::shared_ptr < BasePieceEvent > > ServiceTable::getSpecialEvents(const std::shared_ptr < Piece > &piece,
                                                                                  const int &newX, const int &newY){
    std::vector < std::shared_ptr < BasePieceEvent > > events;

    if(checkPawnPromotion(piece, newX, newY))
        events.push_back(std::make_unique<PawnPromotionEvent>(piece));

    /* check if there is a piece of the opponent captured during the move of the current piece */
    std::shared_ptr < Piece > removedPiece = table->removePiece(newX, newY);
    if(removedPiece != nullptr)
        events.push_back(std::make_unique<CapturedPieceEvent>(removedPiece));

    /* check if there is enPassant move */
    if(checkEnPassant(piece, newX, newY)) {
        std::shared_ptr<Piece> removedPieceNear = table->removePiece(piece->getX(), newY);
        if (removedPieceNear != nullptr)
            events.push_back(std::make_unique<EnPassantEvent>(removedPieceNear));
    }

    return events;
}

bool ServiceTable::checkPawnPromotion(const std::shared_ptr<Piece> &piece, const int &newX, const int &newY) const{
    if(!piece->isPawn()) return false;
    if(!table->pieceWillBeOnOppositeEdge(newX, newY)) return false;
    return true;
}

bool ServiceTable::checkEnPassant(const std::shared_ptr<Piece> &piece, const int &newX, const int &newY) const {
    if(!piece->isPawn()) return false;
    if(this->history.empty()) return false;
    if(!this->getLastMoveFromHistory()->getPiece()->isPawn()) return false;
    if(this->getLastMoveFromHistory()->getPiece()->getY() != newY) return false;
    if(this->getLastMoveFromHistory()->getPiece()->getX() != piece->getX()) return false;
    return true;
}

void ServiceTable::changeTurn() {
    if(currentPlayer == firstPlayerColor)
        currentPlayer = secondPlayerColor;
    else
        currentPlayer = firstPlayerColor;
}

std::shared_ptr < HistoryMove > ServiceTable::getLastMoveFromHistory() const{
    return this->history[history.size() - 1];
}

std::shared_ptr < Piece > ServiceTable::getKing() const{
    return table->getKing(this->currentPlayer);
}

bool ServiceTable::kingUnprotected() {
    return table->kingUnderAttack(this->currentPlayer);
}

std::vector < std::shared_ptr < BasePieceEvent > > ServiceTable::checkIfTheOpponentKingIsUnderAttack() const{
    std::vector < std::shared_ptr < BasePieceEvent > > events;
    if(currentPlayer == firstPlayerColor && table->getKing(secondPlayerColor)) {
        std::shared_ptr < Piece > piece = table->getKing(secondPlayerColor);
        auto attackers = this->table->underAttack(piece->getX(), piece->getY());
        if (!attackers.empty()) {
            events.push_back(std::make_unique<KingUnderAttackEvent>(piece, attackers));
        }
    }

    if(currentPlayer == secondPlayerColor && table->getKing(firstPlayerColor)) {
        std::shared_ptr < Piece > piece = table->getKing(firstPlayerColor);
        auto attackers = this->table->underAttack(piece->getX(), piece->getY());
        if (!attackers.empty()) {
            events.push_back(std::make_unique<KingUnderAttackEvent>(piece, attackers));
        }
    }
    return events;
}

void ServiceTable::addOpponentKingUnderAttackInHistory() const {
    auto lastHistoryRecord = this->getLastMoveFromHistory();
    auto opponentKingUnderAttack = this->checkIfTheOpponentKingIsUnderAttack();
    for(const auto& event: opponentKingUnderAttack)
        lastHistoryRecord->addGeneratedEvent(event);
}

void ServiceTable::checkGameEnded()  {
    for(auto event: getLastMoveFromHistory()->getGeneratedEvents())
        if(event->getEventType() == king_under_attack){
            auto kingPossiblePositions = this->availableMovesDestinations(event->getPiece()->getX(), event->getPiece()->getY());
            bool allUnderAttack = true;
            for(auto kingPossiblePosition: kingPossiblePositions)
                if(this->table->underAttack(kingPossiblePosition.first, kingPossiblePosition.second).empty()){
                    allUnderAttack = false;
                    break;
                }

            if(allUnderAttack){
                history.back()->addGeneratedEvent(std::make_unique<GameEnded>(currentPlayer));
                this->changeTurn();
            }
        }
}

colors ServiceTable::getCurrentPlayer() const {
    return currentPlayer;
}
