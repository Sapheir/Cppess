//
// Created by TurcaVasile on 21/12/2022.
//

#include <utility>

#include "../domain/pieces/Piece.h"

#ifndef CPPESS_EVENTS_H
#define CPPESS_EVENTS_H

enum Events{
    capture,
    pawn_promotion,
    en_passant,
    castling,
    king_under_attack,
    win,
};

#endif //CPPESS_EVENTS_H
