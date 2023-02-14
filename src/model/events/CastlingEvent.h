//
// Created by Turca Vasile on 14/02/2023.
//

#include "BasePieceEvent.h"

#ifndef CPPESS_CASTLINGEVENT_H
#define CPPESS_CASTLINGEVENT_H

class CastlingEvent: public BasePieceEvent{
public:
    explicit CastlingEvent(std::shared_ptr < Piece > piece): BasePieceEvent{castling, std::move(piece)}{};
};

#endif //CPPESS_CASTLINGEVENT_H
