//
// Created by Turca Vasile on 23/12/2022.
//

#ifndef CPPESS_HISTORY_H
#define CPPESS_HISTORY_H


#include <vector>
#include "../domain/history/HistoryMove.h"

class History {
private:
    std::vector < std::shared_ptr < HistoryMove > > moves;
public:
    History() = default;

    void addMove(const std::shared_ptr < HistoryMove > &move);

    std::shared_ptr < HistoryMove > getLastMove();

    History(const History &other){
        this->moves = other.moves;
    };

    History(History &&other) noexcept {
        this->moves = other.moves;
    };

    History operator=(const History &other){
        this->moves = other.moves;
        return *this;
    };

    History operator=(History &&other) noexcept {
        this->moves = other.moves;
        return *this;
    };

};


#endif //CPPESS_HISTORY_H
