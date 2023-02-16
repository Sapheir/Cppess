//
// Created by Turca Vasile on 14/02/2023.
//

#ifndef CPPESS_BASEPIECEEVENT_H
#define CPPESS_BASEPIECEEVENT_H

#include "BaseEvent.h"


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

#endif //CPPESS_BASEPIECEEVENT_H
