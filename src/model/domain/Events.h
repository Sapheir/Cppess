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

class PawnPromotionEvent: public BaseEvent{
public:
    std::shared_ptr < Piece > piece;

public:
    explicit PawnPromotionEvent(std::shared_ptr < Piece > piece): BaseEvent{pawn_promotion}, piece{std::move(piece)}{};

    /**
     * Returns the piece of the current event
     * @return std::shared_ptr < Piece >
     */
    [[nodiscard]] std::shared_ptr<Piece> getPiece() const override{
        return piece;
    }
};

class CapturedPieceEvent: public BaseEvent{
public:
    std::shared_ptr < Piece > piece;

public:
    explicit CapturedPieceEvent(std::shared_ptr < Piece > piece): BaseEvent(capture), piece{std::move(piece)}{};

    CapturedPieceEvent(const CapturedPieceEvent &other) : BaseEvent(other.getEventType()) {
        piece = other.getPiece();
    };

    CapturedPieceEvent(CapturedPieceEvent &&other)  noexcept : BaseEvent(other.getEventType()) {
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

class EnPassantEvent: public BaseEvent{
public:
    std::shared_ptr < Piece > piece;

public:
    explicit EnPassantEvent(std::shared_ptr < Piece > piece): BaseEvent(en_passant), piece{std::move(piece)}{};

    EnPassantEvent(const EnPassantEvent &other) : BaseEvent(other.getEventType()) {
        piece = other.getPiece();
    };

    EnPassantEvent(EnPassantEvent &&other)  noexcept : BaseEvent(other.getEventType()) {
        piece = other.getPiece();
    };

    /**
     * Returns the piece of the current event
     * @return std::shared_ptr < Piece >
     */
    [[nodiscard]] std::shared_ptr < Piece > getPiece() const override{
        return piece;
    }
};

class KingUnderAttackEvent: public BaseEvent{
private:
    std::shared_ptr < Piece > piece;
    std::vector < std::pair < int, int > > attackersPositions;
public:
    explicit KingUnderAttackEvent(std::shared_ptr < Piece > piece): BaseEvent(king_under_attack),
                                                                    piece{std::move(piece)}{};

    explicit KingUnderAttackEvent(std::shared_ptr < Piece > piece, std::vector < std::pair < int, int >> attackersPositions):
                            BaseEvent(king_under_attack), piece{std::move(piece)}, attackersPositions{std::move(attackersPositions)}{};

    [[nodiscard]] std::shared_ptr < Piece > getPiece() const override{
        return piece;
    }

    [[nodiscard]] auto getAttackersPositions() const{
        return attackersPositions;
    }
};

#endif //CPPESS_EVENTS_H
