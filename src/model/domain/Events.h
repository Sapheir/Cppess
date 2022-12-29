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
};

class BasePieceEvent: public BaseEvent{

public:
    explicit BasePieceEvent(const Events &eventType): BaseEvent(eventType){};

    BasePieceEvent() : BaseEvent(){};

    BasePieceEvent(const BasePieceEvent &other):BaseEvent(other.getEventType()){
    };

    BasePieceEvent(BasePieceEvent &&other) noexcept :BaseEvent(other.getEventType())  {};
};

class PawnPromotionEvent: public BasePieceEvent{
private:
    std::shared_ptr < Piece > piece;
public:
    explicit PawnPromotionEvent(std::shared_ptr < Piece > piece): BasePieceEvent{pawn_promotion}{
        this->piece = std::move(piece);
    };

    /**
     * Returns the piece of the current event
     * @return std::shared_ptr < Piece >
     */
    [[nodiscard]] std::shared_ptr<Piece> getPiece() const{
        return piece;
    }

};

class CapturedPieceEvent: public BasePieceEvent{
private:
    std::shared_ptr < Piece > piece;
public:
    explicit CapturedPieceEvent(std::shared_ptr < Piece > piece): BasePieceEvent(capture){
        this->piece = std::move(piece);
    };

    CapturedPieceEvent(const CapturedPieceEvent &other) : BasePieceEvent(other.getEventType()) {
    };

    CapturedPieceEvent(CapturedPieceEvent &&other)  noexcept : BasePieceEvent(other.getEventType()) {
    };

    /**
     * Returns the piece of the current event
     * @return std::shared_ptr < Piece >
     */
    [[nodiscard]] std::shared_ptr<Piece> getPiece() const{
        return piece;
    }
};

class EnPassantEvent: public BasePieceEvent{
private:
    std::shared_ptr < Piece > piece;
public:
    explicit EnPassantEvent(std::shared_ptr < Piece > piece): BasePieceEvent(en_passant){
        this->piece = std::move(piece);
    };

    EnPassantEvent(const EnPassantEvent &other) : BasePieceEvent(other.getEventType()) {
        this->piece = std::move(piece);
    };

    EnPassantEvent(EnPassantEvent &&other)  noexcept : BasePieceEvent(other.getEventType()) {
        this->piece = std::move(piece);
    };

    /**
     * Returns the piece of the current event
     * @return std::shared_ptr < Piece >
     */
    [[nodiscard]] std::shared_ptr<Piece> getPiece() const{
        return piece;
    }

};

class KingUnderAttackEvent: public BasePieceEvent{
private:
    std::shared_ptr < Piece > piece;
    std::vector < std::pair < int, int > > attackersPositions;
public:
    explicit KingUnderAttackEvent(std::shared_ptr < Piece > piece): BasePieceEvent(king_under_attack){
        this->piece = std::move(piece);
    };

    explicit KingUnderAttackEvent(std::shared_ptr < Piece > piece, std::vector < std::pair < int, int >> attackersPositions):
            BasePieceEvent(king_under_attack), attackersPositions{std::move(attackersPositions)}{
        this->piece = std::move(piece);
    };

    [[nodiscard]] auto getAttackersPositions() const{
        return attackersPositions;
    }

    /**
     * Returns the piece of the current event
     * @return std::shared_ptr < Piece >
     */
    [[nodiscard]] std::shared_ptr<Piece> getPiece() const{
        return piece;
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

    };

};

#endif //CPPESS_EVENTS_H
