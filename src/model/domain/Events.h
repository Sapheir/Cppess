//
// Created by TurcaVasile on 21/12/2022.
//

#include <utility>

#include "pieces/Piece.h"

#ifndef CPPESS_EVENTS_H
#define CPPESS_EVENTS_H

enum Events{
    capture,
    pawn_promotion,
    en_passant_promotion,
    castling
};

class BaseEvent{
    Events eventType;
public:
    explicit BaseEvent(const Events &eventType): eventType{eventType}{};

    BaseEvent(){
        eventType = capture;
    }

    BaseEvent(const BaseEvent &other){
        this->eventType = other.eventType;
    };

    BaseEvent(BaseEvent &&other) noexcept {
        this->eventType = other.eventType;
    };

    [[nodiscard]] Events getEventType() const{
        return eventType;
    };

    [[nodiscard]] virtual std::shared_ptr < Piece > getPiece() const = 0;


};

class PawnPromotion: public BaseEvent{
public:
    std::shared_ptr < Piece > piece;

public:
    explicit PawnPromotion(std::shared_ptr < Piece > piece): BaseEvent{pawn_promotion}, piece{std::move(piece)}{};

    /**
     * Returns the piece of the current event
     * @return std::shared_ptr < Piece >
     */
    [[nodiscard]] std::shared_ptr<Piece> getPiece() const override{
        return piece;
    }
};

class CapturedPiece: public BaseEvent{
public:
    std::shared_ptr < Piece > piece;

public:
    explicit CapturedPiece(std::shared_ptr < Piece > piece): BaseEvent(capture), piece{std::move(piece)}{};

    CapturedPiece(const CapturedPiece &other) : BaseEvent(other.getEventType()) {
        piece = other.getPiece();
    };

    CapturedPiece(CapturedPiece &&other)  noexcept : BaseEvent(other.getEventType()) {
        piece = other.getPiece();
    };

    /**
     * Returns the piece of the current event
     * @return std::shared_ptr < Piece >
     */
    [[nodiscard]] std::shared_ptr<Piece> getPiece() const override{
        return piece;
    }


};


#endif //CPPESS_EVENTS_H
