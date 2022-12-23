//
// Created by Turca Vasile on 22/12/2022.
//

#include "HistoryMove.h"

std::vector<std::shared_ptr<BaseEvent> > HistoryMove::getAllGeneratedEvents() {
    return generatedEvents;
}
