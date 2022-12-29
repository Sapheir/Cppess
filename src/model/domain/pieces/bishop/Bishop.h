//
// Created by Turca Vasile
//
#include <vector>
#include "../Piece.h"

#ifndef CPPESS_BISHOP_H
#define CPPESS_BISHOP_H

class Bishop: public Piece {
private:

public:
    Bishop(const int &positionX, const int &positionY, const colors &color):Piece{positionX, positionY, color}{};;

    /**
     * Return a list of all possible positions inside the chess table where the bishop could be moved
     *
     * @param tableSize: the size of the table
     *
     * @return vector < pair < int, int > > - all possible positions
     */
    [[nodiscard]] std::vector<std::pair<int, int>> nextPositions(const int &tableSize) const override;

    /**
     * Returns false because current piece is not a knight
     * @return bool
     */
    [[nodiscard]] bool isKnight() const override;

    /**
     * Returns false because current piece is not a pawn
     * @return bool
     */
    [[nodiscard]] bool isPawn() const override;

    /**
     * Returns false because current piece is not a king
     * @return bool
     */
    [[nodiscard]] bool isKing() const override;

};

#endif //CPPESS_BISHOP_H