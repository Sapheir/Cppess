//
// Created by Turca Vasile on 14/02/2023.
//

#include "Events.h"
#include "../domain/pieces/king/King.h"
#include "../domain/pieces/rook/Rook.h"

#ifndef CPPESS_BASEEVENT_H
#define CPPESS_BASEEVENT_H


class BaseEvent{
    Events eventType;
public:
    BaseEvent()= default;
    explicit BaseEvent(Events eventType): eventType{eventType}{};

    [[nodiscard]] virtual std::shared_ptr < Piece > getPiece() const{
        return {};
    };

    [[nodiscard]] Events getEventType() const{
        return eventType;
    };

    [[nodiscard]] virtual std::vector < std::pair < int, int > > getAttackers() const{
        return {};
    }

    [[nodiscard]] virtual std::pair < int, int > getKingPosBeforeCastle() const{
        return {};
    }

    [[nodiscard]] virtual std::pair < int, int > getKingPosAfterCastle() const{
        return {};
    }

    [[nodiscard]] virtual std::pair < int, int > getRookPosBeforeCastle() const{
        return {};
    }

    [[nodiscard]] virtual std::pair < int, int > getRookPosAfterCastle() const{
        return {};
    }

};

#endif //CPPESS_BASEEVENT_H
