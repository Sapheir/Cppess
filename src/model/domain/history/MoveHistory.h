//
// Created by Turca Vasile on 22/12/2022.
//

#ifndef CPPESS_MOVEHISTORY_H
#define CPPESS_MOVEHISTORY_H

#include "../pieces/Piece.h"
#include "../Events.h"

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
                 const std::shared_ptr < Piece > &piece):oldX{oldX}, oldY{oldY}, newX{newX}, newY{newY}, piece{piece}{};

    /**
     * Add an event that was caused by the current move
     * @param generatedEvent - std::shared_ptr < BaseEvent >
     */
    void addGeneratedEvent(std::shared_ptr < BaseEvent > generatedEvent){
        this->generatedEvents.push_back(generatedEvent);
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

    [[nodiscard]]std::vector < std::shared_ptr < BaseEvent > > getGeneratedEvents() const{
        return generatedEvents;
    }

};


#endif //CPPESS_MOVEHISTORY_H
