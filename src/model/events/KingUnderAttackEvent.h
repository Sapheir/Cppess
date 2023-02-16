//
// Created by User on 16/02/2023.
//

#ifndef CPPESS_KINGUNDERATTACKEVENT_H
#define CPPESS_KINGUNDERATTACKEVENT_H


#include "BasePieceEvent.h"

class KingUnderAttackEvent: public BasePieceEvent{
private:
    std::vector < std::pair < int, int > > attackersPositions;
public:
    explicit KingUnderAttackEvent(std::shared_ptr < Piece > piece): BasePieceEvent(king_under_attack, piece){
    };

    explicit KingUnderAttackEvent(std::shared_ptr < Piece > piece, std::vector < std::pair < int, int >> attackersPositions):
            BasePieceEvent(king_under_attack, piece), attackersPositions{std::move(attackersPositions)}{};

    [[nodiscard]]  std::vector < std::pair < int, int > > getAttackers() const override{
        return attackersPositions;
    }
};

#endif //CPPESS_KINGUNDERATTACKEVENT_H
