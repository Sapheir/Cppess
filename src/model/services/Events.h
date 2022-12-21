//
// Created by TurcaVasile on 21/12/2022.
//

#include <utility>

#include "../pieces/Piece.h"

#ifndef CPPESS_EVENTS_H
#define CPPESS_EVENTS_H

enum Events{
    capture,
    pawn_promotion,
    en_passant_promotion,
    castling
};

struct BaseEvent{
public:
    Events eventType;
    explicit BaseEvent(const Events &eventType): eventType{eventType}{};

    [[nodiscard]] virtual std::shared_ptr < Piece > getPiece() const = 0;
};

struct PawnPromotion: public BaseEvent{
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

struct CapturedPiece: public BaseEvent{
public:
    std::shared_ptr < Piece > piece;

public:
    explicit CapturedPiece(std::shared_ptr < Piece > piece): BaseEvent(capture), piece{std::move(piece)}{};

    /**
     * Returns the piece of the current event
     * @return std::shared_ptr < Piece >
     */
    [[nodiscard]] std::shared_ptr<Piece> getPiece() const override{
        return piece;
    }
};


#endif //CPPESS_EVENTS_H
