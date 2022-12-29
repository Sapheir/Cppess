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
    en_passant,
    castling,
    king_under_attack
};

class BaseEvent{
    Events eventType;
    std::shared_ptr < Piece > piece;
public:
    explicit BaseEvent(const Events &eventType, std::shared_ptr < Piece > piece): eventType{eventType}, piece{std::move(piece)}{};

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

    /**
     * Returns the piece of the current event
     * @return std::shared_ptr < Piece >
     */
    [[nodiscard]] std::shared_ptr<Piece> getPiece() const{
        return piece;
    }


};

class PawnPromotionEvent: public BaseEvent{
public:
    explicit PawnPromotionEvent(std::shared_ptr < Piece > piece): BaseEvent{pawn_promotion, piece}{};
};

class CapturedPieceEvent: public BaseEvent{
public:
    explicit CapturedPieceEvent(std::shared_ptr < Piece > piece): BaseEvent(capture, piece){};

    CapturedPieceEvent(const CapturedPieceEvent &other) : BaseEvent(other.getEventType(), other.getPiece()) {
    };

    CapturedPieceEvent(CapturedPieceEvent &&other)  noexcept : BaseEvent(other.getEventType(), other.getPiece()) {
    };
};

class EnPassantEvent: public BaseEvent{
public:
    explicit EnPassantEvent(std::shared_ptr < Piece > piece): BaseEvent(en_passant, piece){};

    EnPassantEvent(const EnPassantEvent &other) : BaseEvent(other.getEventType(), other.getPiece()) {};

    EnPassantEvent(EnPassantEvent &&other)  noexcept : BaseEvent(other.getEventType(), other.getPiece()) {};
};

class KingUnderAttackEvent: public BaseEvent{
private:
    std::vector < std::pair < int, int > > attackersPositions;
public:
    explicit KingUnderAttackEvent(std::shared_ptr < Piece > piece): BaseEvent(king_under_attack, piece){};

    explicit KingUnderAttackEvent(std::shared_ptr < Piece > piece, std::vector < std::pair < int, int >> attackersPositions):
                            BaseEvent(king_under_attack, piece), attackersPositions{std::move(attackersPositions)}{};

    [[nodiscard]] auto getAttackersPositions() const{
        return attackersPositions;
    }
};

#endif //CPPESS_EVENTS_H
