// Created by Catalin
#pragma once

#include "../../model/domain/pieces/pieces.h"

struct move {
    piece_info pieceInfo;
    int newPosX, newPosY;
};

inline std::ostream &operator<<(std::ostream &out, move const &m) {
    return out << m.pieceInfo.color << ";" << m.pieceInfo.piece_type << ";" << m.pieceInfo.posX
               << ";" << m.pieceInfo.posY << ";" << m.newPosX << ";" << m.newPosY;
}

inline std::istream &operator>>(std::istream &in, move &m) {
    char separator;

    bool ok = in >> m.pieceInfo.color
              && in >> separator && separator == ';'
              && in >> m.pieceInfo.piece_type
              && in >> separator && separator == ';'
              && in >> m.pieceInfo.posX
              && in >> separator && separator == ';'
              && in >> m.pieceInfo.posY
              && in >> separator && separator == ';'
              && in >> m.newPosX
              && in >> separator && separator == ';'
              && in >> m.newPosY
    ;

    if (!ok)
        in.setstate(std::ios::failbit);

    return in;
}