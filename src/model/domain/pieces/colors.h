//
// Created by Turca Vasile
//

#ifndef COLORS
#define COLORS
#include <iostream>

enum colors{
    black = 0,
    white = 1,
    red = 2,
    orange = 3,
    yellow = 4,
    green = 5,
    violet = 6,
    blue = 7,
    purple = 8,
};

inline std::istream &operator>>(std::istream &in, colors &c) {
    std::string buf;
    in >> buf;
    try {
        int index = std::stoi(buf);
        if (index < 0 || index > 8)
            in.setstate(std::ios::failbit);
    } catch (std::exception &e) {
        in.setstate(std::ios::failbit);
    }
    return in;
}

inline std::ostream &operator<<(std::ostream &out, colors const &c) {
    out << std::to_string(c);
    return out;
}

#endif