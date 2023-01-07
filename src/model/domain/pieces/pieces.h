// Created by Catalin
#pragma once
#include "colors.h"

enum piece_types {
    rook = 0,
    knight = 1,
    bishop = 2,
    queen = 3,
    king = 4,
    pawn = 5
};

inline std::ostream &operator<<(std::ostream &out, piece_types const &p) {
    out << std::to_string(p);
    return out;
}

inline std::istream &operator>>(std::istream &in, piece_types &p) {
    std::string buf;
    in >> buf;
    try {
        int index = std::stoi(buf);
        if (index < 0 || index > 5)
            in.setstate(std::ios::failbit);
    } catch (std::exception &e) {
        in.setstate(std::ios::failbit);
    }
    return in;
}

struct piece_info {
    piece_types piece_type;
    int posX, posY;
    colors color;
};

inline std::ostream &operator<<(std::ostream &out, piece_info const &p) {
    return out << p.piece_type << ";" << p.posX << ";" << p.posY << ";" << p.color;
}

inline std::istream &operator>>(std::istream &in, piece_info &p) {
    char separator;
    bool ok = in >> p.piece_type
              && in >> separator && separator == ';'
              && in >> p.posX
              && in >> separator && separator == ';'
              && in >> p.posY
              && in >> separator && separator == ';'
              && in >> p.color
    ;
    if (!ok)
        in.setstate(std::ios::failbit);

    return in;
}

