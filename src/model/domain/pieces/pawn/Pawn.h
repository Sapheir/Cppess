//
// Created by Turca Vasile
//
#include "../Piece.h"
#include <vector>

#ifndef CPPESS_PAWN_H
#define CPPESS_PAWN_H

class Pawn: public Piece {
private:
    bool doubleMoveAvailable;
public:
    Pawn(const int &positionX, const int &positionY, const colors &color):Piece{positionX, positionY, color}{
        doubleMoveAvailable = true;
    };

    /**
     * Return a list of all possible positions inside the chess table where the bishop could be moved
     *
     * @param tableSize: the size of the table
     *
     * @return vector < pair < int, int > > - all possible positions
     */
    [[nodiscard]] std::vector < std::pair < int, int > > nextPositions(const int &tableSize) const override;

    /**
     * Returns false because current piece is not a knight
     * @return bool
     */
    [[nodiscard]] bool isKnight() const override;

    /**
     * Returns true because current piece is a pawn
     * @return bool
     */
    [[nodiscard]] bool isPawn() const override;

    /**
     * Returns false because current piece is not a king
     * @return bool
     */
    [[nodiscard]] bool isKing() const override;

    /**
     * Disable the possibility of a pawn to double move
     */
    void doubleMoveDisable() override;

    /**
     * Returns false because current piece is not a rook
     * @return bool
     */
    [[nodiscard]] bool isRook() const override;

};

#endif //CPPESS_PAWN_H
