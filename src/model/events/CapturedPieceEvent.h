//
// Created by Turca Vasile on 14/02/2023.
//

#ifndef CPPESS_CAPTUREDPIECEEVENT_H
#define CPPESS_CAPTUREDPIECEEVENT_H

#include "BasePieceEvent.h"

class CapturedPieceEvent: public BasePieceEvent{
public:
    explicit CapturedPieceEvent(std::shared_ptr < Piece > piece): BasePieceEvent(capture, std::move(piece)){};

    CapturedPieceEvent(const CapturedPieceEvent &other) : BasePieceEvent(other.getEventType(), other.getPiece()) {};

    CapturedPieceEvent(CapturedPieceEvent &&other)  noexcept : BasePieceEvent(other.getEventType(), other.getPiece()) {};
};

#endif //CPPESS_CAPTUREDPIECEEVENT_H
