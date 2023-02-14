//
// Created by Turca Vasile on 14/02/2023.
//

#ifndef CPPESS_ENPASSANTEVENT_H
#define CPPESS_ENPASSANTEVENT_H

#include "BasePieceEvent.h"

class EnPassantEvent: public BasePieceEvent{
public:
    explicit EnPassantEvent(std::shared_ptr < Piece > piece): BasePieceEvent(en_passant, std::move(piece)){};

    EnPassantEvent(const EnPassantEvent &other) : BasePieceEvent(other.getEventType(), other.getPiece()) {};

    EnPassantEvent(EnPassantEvent &&other)  noexcept : BasePieceEvent(other.getEventType(), other.getPiece()) {};

};

#endif //CPPESS_ENPASSANTEVENT_H
