//
// Created by Turca Vasile on 14/02/2023.
//

#include "BasePieceEvent.h"

#ifndef CPPESS_PAWNPROMOTIONEVENT_H
#define CPPESS_PAWNPROMOTIONEVENT_H

class PawnPromotionEvent: public BasePieceEvent{
public:
    explicit PawnPromotionEvent(std::shared_ptr < Piece > piece): BasePieceEvent{pawn_promotion, std::move(piece)}{};
};

#endif //CPPESS_PAWNPROMOTIONEVENT_H
