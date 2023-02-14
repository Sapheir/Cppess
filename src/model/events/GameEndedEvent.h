//
// Created by Turca Vasile on 14/02/2023.
//

#ifndef CPPESS_GAMEENDEDEVENT_H
#define CPPESS_GAMEENDEDEVENT_H

#include "BaseEvent.h"

class GameEnded: public BaseEvent{
private:
    colors winner;
public:
    explicit GameEnded(colors winner):BaseEvent(win){
        this->winner = winner;
    };

    /**
     * Returns the winner of the game
     */
    colors getWinner(){
        return this->winner;
    }

    [[nodiscard]] std::shared_ptr<Piece> getPiece() const{
        return nullptr;
    };

};

#endif //CPPESS_GAMEENDEDEVENT_H
