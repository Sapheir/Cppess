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
    king_under_attack,
    win
};

class BaseEvent{
    Events eventType;
public:
    BaseEvent()= default;
    explicit BaseEvent(Events eventType): eventType{eventType}{};

    [[nodiscard]] virtual std::shared_ptr < Piece > getPiece() const = 0;

    [[nodiscard]] Events getEventType() const{
        return eventType;
    };

    [[nodiscard]] virtual std::vector < std::pair < int, int > > getAttackers() const{
        return {};
    }
};

class BasePieceEvent: public BaseEvent{
private:
    std::shared_ptr < Piece > piece;
public:
    explicit BasePieceEvent(const Events &eventType, std::shared_ptr < Piece > piece): BaseEvent(eventType){
        this->piece = std::move(piece);
    };

    BasePieceEvent() : BaseEvent(){};

    BasePieceEvent(const BasePieceEvent &other):BaseEvent(other.getEventType()){
        this->piece = std::move(piece);
    };

    BasePieceEvent(BasePieceEvent &&other) noexcept :BaseEvent(other.getEventType())  {
        this->piece = std::move(piece);
    };

    /**
     * Returns the piece of the current event
     * @return std::shared_ptr < Piece >
     */
    [[nodiscard]] std::shared_ptr<Piece> getPiece() const override{
        return piece;
    }
};

class PawnPromotionEvent: public BasePieceEvent{
public:
    explicit PawnPromotionEvent(std::shared_ptr < Piece > piece): BasePieceEvent{pawn_promotion, std::move(piece)}{};
};

class CapturedPieceEvent: public BasePieceEvent{
public:
    explicit CapturedPieceEvent(std::shared_ptr < Piece > piece): BasePieceEvent(capture, std::move(piece)){};

    CapturedPieceEvent(const CapturedPieceEvent &other) : BasePieceEvent(other.getEventType(), other.getPiece()) {};

    CapturedPieceEvent(CapturedPieceEvent &&other)  noexcept : BasePieceEvent(other.getEventType(), other.getPiece()) {};
};

class EnPassantEvent: public BasePieceEvent{
public:
    explicit EnPassantEvent(std::shared_ptr < Piece > piece): BasePieceEvent(en_passant, std::move(piece)){};

    EnPassantEvent(const EnPassantEvent &other) : BasePieceEvent(other.getEventType(), other.getPiece()) {};

    EnPassantEvent(EnPassantEvent &&other)  noexcept : BasePieceEvent(other.getEventType(), other.getPiece()) {};

};

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

class GameEnded: public BaseEvent{
private:
    colors winner;
public:
    explicit GameEnded(colors winner):BaseEvent(win){
        this->winner = winner;
    };

    /**
     * Returns the winner of the game
     */
    colors getWinner(){
        return this->winner;
    }

    [[nodiscard]] std::shared_ptr<Piece> getPiece() const{
        return nullptr;
    };

};

#endif //CPPESS_EVENTS_H
