//
// Created by Turca Vasile on 22/12/2022.
//

#ifndef CPPESS_HISTORYMOVE_H
#define CPPESS_HISTORYMOVE_H

#include <utility>
#include <iostream>

#include "../pieces/Piece.h"
#include "../../events/Events.h"
#include "../../events/BaseEvent.h"

class HistoryMove{
private:
    int oldX, oldY, newX, newY;
    std::shared_ptr < Piece > piece;
    std::vector < std::shared_ptr < BaseEvent > > generatedEvents;
public:

    /**
     * Constructor for the move from history
     * @param (oldX, oldY) - (int, int)
     * @param (newX, newY) - (int, int)
     * @param piece - std::shared_ptr < Piece >
     */
    HistoryMove(const int &oldX, const int &oldY, const int &newX, const int &newY,
                 std::shared_ptr < Piece > piece):oldX{oldX}, oldY{oldY}, newX{newX}, newY{newY}, piece{std::move(piece)}{};

    /**
     * Add an event that was caused by the current move
     * @param generatedEvent - std::shared_ptr < BasePieceEvent >
     */
    void addGeneratedEvent(const std::shared_ptr < BaseEvent >& generatedEvent){
        this->generatedEvents.push_back(generatedEvent);
    }

    /**
     * Returns all generated events
     * @return
     */
    [[nodiscard]]std::vector < std::shared_ptr < BaseEvent > > getGeneratedEvents() const{
        return generatedEvents;
    }

    [[nodiscard]] int getOldX() const{
        return oldX;
    }

    [[nodiscard]] int getOldY() const{
        return oldY;
    }

    [[nodiscard]] int getNewX() const{
        return newX;
    }

    [[nodiscard]] int getNewY() const{
        return newY;
    }

    [[nodiscard]]std::shared_ptr < Piece > getPiece() const{
        return piece;
    }

    HistoryMove(){};

    HistoryMove(const HistoryMove &other){
        this->piece = other.piece;
        this->generatedEvents = other.generatedEvents;
        this->oldX = other.oldX;
        this->oldY = other.oldY;
        this->newX = other.newX;
        this->newY = other.newY;
    };

    HistoryMove& operator=(const HistoryMove &other){
        this->piece = other.piece;
        this->generatedEvents = other.generatedEvents;
        this->oldX = other.oldX;
        this->oldY = other.oldY;
        this->newX = other.newX;
        this->newY = other.newY;
        return *this;
    };

    HistoryMove& operator=(const HistoryMove &&other){
        this->piece = other.piece;
        this->generatedEvents = other.generatedEvents;
        this->oldX = other.oldX;
        this->oldY = other.oldY;
        this->newX = other.newX;
        this->newY = other.newY;
        return *this;
    };

    HistoryMove(HistoryMove &&other) noexcept {
        this->piece = other.piece;
        this->generatedEvents = other.generatedEvents;
        this->oldX = other.oldX;
        this->oldY = other.oldY;
        this->newX = other.newX;
        this->newY = other.newY;
    };

};


#endif //CPPESS_HISTORYMOVE_H
