//
// Created by Turca Vasile on 14/02/2023.
//

#include "Events.h"

#ifndef CPPESS_BASEEVENT_H
#define CPPESS_BASEEVENT_H


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

#endif //CPPESS_BASEEVENT_H
