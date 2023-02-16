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
    auto destinations =  table->availableMovesDestinations(posX, posY);

    if(!history.empty())
        if(!this->getLastMoveFromHistory()->getGeneratedEvents().empty()){
            auto events = this->getLastMoveFromHistory()->getGeneratedEvents();
            for(const auto &event: events)
                if(event->getEventType() == king_under_attack){
                    if(event->getPiece()->getX() != posX || event->getPiece()->getY() != posY)
                        return {};
                    auto attackers = event->getAttackers();
                    std::vector < std::pair < int, int > > freeDestinations;
                    if(attackers.size() == 1){
                        for(auto it : destinations)
                            if(it.first == attackers[0].first && it.second == attackers[0].second)
                                freeDestinations.push_back(it);
                    }
                    for(const auto &destination: destinations) {
                        auto positionAttackers = this->table->underAttack(destination.first, destination.second);
                        bool allAttackerFromCurrentColor = true;
                        for(const auto &attacker: positionAttackers) {
                            if (getPiece(attacker.first, attacker.second)->getColor() != currentPlayer)
                                allAttackerFromCurrentColor = false;
                        }
                        if(allAttackerFromCurrentColor)
                            freeDestinations.push_back(destination);
                    }
                    return freeDestinations;
                }
        }

    if(piece->isKing()){
        std::vector < std::pair < int, int > >  freeDestinations;
        for(const auto &destination: destinations) {
            auto positionAttackers = this->table->underAttack(destination.first, destination.second);
            bool allAttackerFromCurrentColor = true;
            for(const auto &attacker: positionAttackers) {
                if (getPiece(attacker.first, attacker.second)->getColor() != currentPlayer)
                    allAttackerFromCurrentColor = false;
            }
            if(allAttackerFromCurrentColor)
                freeDestinations.push_back(destination);
        }
        return freeDestinations;
    }

    return destinations;
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

bool ServiceTable::noCoordinateUnderAttackBtw(int posX, int posY, int newX, int newY) const{
    for(int X = std::min(posX, newX) ; X < std::max(posX, newX) ; X++)
        for(int Y = std::min(posY, newY) ; Y <= std::max(posY, newY) ; Y++){
            if(X == posX && Y == posY) continue;
            if(X == newX && Y == newY) continue;
            for(auto attackers: this->table->underAttack(X, Y)){
                if(this->table->getPiece(attackers.first, attackers.second)->getColor() != this->currentPlayer)
                    return false;
            }
        }
    return true;
}


bool ServiceTable::isCastle(int posX, int posY, int newX, int newY) {
    std::shared_ptr<Piece> theKing = table->getPiece(posX, posY);
    if(!theKing || !theKing->isKing() || !theKing->getFirstMove())
        return false;
    std::shared_ptr<Piece> theRook = table->getPiece(newX, newY);
    if(!theRook || !theRook->isRook() || !theKing->getFirstMove())
        return false;

    if(!this->table->underAttack(theRook->getX(), theRook->getY()).empty())
        return false;

    if(theRook->getColor() != theKing->getColor()) return false;

    if(theRook->getY() != theKing ->getY()) return false;

    if(!table->noPieceBetween(posX, posY, newX, newY)) return false;

    if(!this->noCoordinateUnderAttackBtw(posX, posY, newX, newY)) return false;

    return true;
}

std::pair<int, int> ServiceTable::computeNewCoordinatesCastlingKing(const std::pair<int, int> &kingPos,
                                                                         const std::pair<int, int> &rookPos) {
    return std::make_pair(kingPos.first + (rookPos.first - kingPos.first > 0 ? 2:-2), kingPos.second);
}

std::pair<int, int> ServiceTable::computeNewCoordinatesCastlingRook(const std::pair<int, int> &kingPos,
                                                                    const std::pair<int, int> &rookPos) {
    return std::make_pair(kingPos.first + (rookPos.first - kingPos.first > 0 ? 1:-1), kingPos.second);
}

std::vector<std::shared_ptr<BaseEvent> >
ServiceTable::castlePieces(const int &x, const int &y, const int &newX, const int &newY) {
    std::vector < std::shared_ptr < BaseEvent > > events;
    std::pair < int, int > newKing = computeNewCoordinatesCastlingKing({x,y}, {newX, newY});
    std::pair < int, int > newRook = computeNewCoordinatesCastlingRook({x, y}, {newX, newY});

    std::shared_ptr<Piece> king = this->table->getPiece(x, y);
    this->table->movePieceOnValidDestination(king, newKing.first, newKing.second);

    std::shared_ptr<Piece> rook = this->table->getPiece(newX, newY);
    this->table->movePieceOnValidDestination(rook, newRook.first, newRook.second);

    events.push_back(std::make_unique<CastlingEvent>(std::make_pair(x, y), std::make_pair(newX, newY), newKing, newRook));

    auto kingUnderAttackEvents = checkIfTheOpponentKingIsUnderAttack();
    for(const auto &event: kingUnderAttackEvents)
        events.push_back(event);
    return events;
}


std::vector < std::shared_ptr < BaseEvent > > ServiceTable::movePiece(const int &x, const int &y,
                                                                           const int &newX, const int &newY){
    if(this->isCastle(x, y, newX, newY)) {
        return castlePieces(x, y, newX, newY);
    }

    if(this->isCastle(newX, newY, x, y)){
        return castlePieces(newX, newY, x, y);
    }

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
    for(auto event: getLastMoveFromHistory()->getGeneratedEvents()) {
        if (event->getEventType() == king_under_attack) {
            this->changeTurn();
            auto kingPossiblePositions = this->availableMovesDestinations(event->getPiece()->getX(),
                                                                          event->getPiece()->getY());
            this->changeTurn();

            bool allUnderAttack = kingPossiblePositions.empty();
            if (allUnderAttack) {
                history.back()->addGeneratedEvent(std::make_unique<GameEnded>(currentPlayer));
                this->changeTurn();
                return;
            }
        }
    }
}

colors ServiceTable::getCurrentPlayer() const {
    return currentPlayer;
}
