//
// Created by Turca Vasile
//

#include <vector>
#include "../Piece.h"

#ifndef CPPESS_KNIGHT_H
#define CPPESS_KNIGHT_H

class Knight: public Piece {
private:

public:
    Knight(const int &positionX, const int &positionY, const colors &color):Piece{positionX, positionY, color}{};

    /**
     * Return a list of all possible positions inside the chess table where the bishop could be moved
     *
     * @param tableSize: the size of the table
     *
     * @return vector < pair < int, int > > - all possible positions
     */
    [[nodiscard]] std::vector < std::pair < int, int > > nextPositions(const int &tableSize) const override;

    /**
     * Returns true because current piece is a knight
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

    /**
     * Returns false because current piece is not a rook
     * @return bool
     */
    [[nodiscard]] bool isRook() const override;

};

#endif //CPPESS_KNIGHT_H
