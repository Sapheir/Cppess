//
// Created by Turca Vasile on 14/02/2023.
//

#include "BasePieceEvent.h"

#ifndef CPPESS_CASTLINGEVENT_H
#define CPPESS_CASTLINGEVENT_H

class CastlingEvent: public BaseEvent{
private:
    std::pair < int, int > newKingPos;
    std::pair < int, int > newRookPos;
    std::pair < int, int > oldKingPos;
    std::pair < int, int > oldRookPos;
public:
    explicit CastlingEvent(const std::pair<int,int> &oldKingPos, const std::pair<int,int> &oldRookPos,
                           const std::pair<int,int> &newKingPos, const std::pair<int,int> &newRookPos):
    BaseEvent{castling}, oldKingPos{oldKingPos}, oldRookPos{oldRookPos},
                                  newKingPos{newKingPos}, newRookPos{newRookPos}{};


    [[nodiscard]] std::pair < int, int > getKingPosBeforeCastle() const override{
        return oldKingPos;
    }

    [[nodiscard]] std::pair < int, int > getKingPosAfterCastle() const override{
        return newKingPos;
    }

    [[nodiscard]] std::pair < int, int > getRookPosBeforeCastle() const override{
        return oldRookPos;
    }

    [[nodiscard]] std::pair < int, int > getRookPosAfterCastle() const override{
        return newRookPos;
    }

};

#endif //CPPESS_CASTLINGEVENT_H
