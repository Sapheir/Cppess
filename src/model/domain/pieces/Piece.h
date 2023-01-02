//
// Created by Turca Vasile
//

#include <vector>
#include <memory>
#include "colors.h"

#ifndef CPPESS_PIECE_H
#define CPPESS_PIECE_H

class Piece {
protected:
    int positionX;
    int positionY;
    colors color;

    /**
     * Check if a coordinate is in range [1, limit]
     *
     * @param position: the coordinate that will be checked
     *
     * return true or false if the coordinate is in range
     */
    static bool inRange(const int  &position, const int &limit);

    /**
     * Check if possible new coordinates for a piece are inside the table
     *
     * @param newPositionX, newPositionY: possible new position of the piece on the chess table
     * @param tableSize: the size of the table
     *
     * return true if the current potential position is on table and false otherwise
     */
    static bool insideSquareTable(const int& newPositionX, const int& newPositionY, const int &tableSize);

    /**
    * Generate all possible movements from the initial position inside the chess table with chosen direction and sense
    *
    * @param initialX, initialY: initial position of the piece on the chess table
    * @param scaleX: parameters that show if the position on X should increase(1) or decrease(-1)
    * @param scaleY: parameters that show if the position on Y should increase(1) or decrease(-1)
    * @param tableSize: the size of the table
    *
    * @return vector < pair < int, int > > - all generated positions
    */
    static std::vector < std::pair < int, int > > addPositions(const int &scaleX, const int &scaleY,
                                                               const int &initialX, const int &initialY, const int &tableSize);

public:

    /** Constructor for piece */
    Piece(const int &positionX, const int &positionY, const colors &color): positionX{positionX}, positionY{positionY}, color{color}{};

    /**
     * Return a list of all possible positions inside the chess table where the bishop could be moved
     *
     * @param tableSize: the size of the table
     *
     * @return vector < pair < int, int > > - all possible positions
     */
    [[nodiscard]] virtual std::vector < std::pair < int, int > > nextPositions(const int &tableSize) const = 0;

    /**
     * Get the offset on X of the piece as an int
     */
    [[nodiscard]] int getX() const;

    /**
     * Get the offset on Y of the piece as an int
     */
    [[nodiscard]] int getY() const;

    /**
     * Set the new value of the positionX
     * @param posX - int
     */
    void setX(int posX);

    /**
     * Set the new value of the positionY
     * @param posY - int
     */
    void setY(int posY);

    /**
     * Returns true or false if the other piece has same coordinates
     * @param other - Piece
     * @return bool
     */
    [[nodiscard]] bool sameCoordinates(const Piece &other) const;

    /**
     * Returns true or false if the other piece has same coordinates
     * @param other - Piece
     * @return bool
     */
    [[nodiscard]] bool sameCoordinates(const int &posX, const int &posY) const;

    /**
     * Returns the color of the current piece
     * @return int
     */
    [[nodiscard]] colors getColor() const;

    /**
     * Sets the newColor of the current piece
     * @param newColor - int
     */
    void setColor(const colors &newColor);

    /**
     * Check if current piece and another piece have same color
     */
     [[nodiscard]] bool sameColor(const std::shared_ptr<Piece> &other) const;

    /**
    * Returns true or if the current piece is a pawn
    * @return bool
    */
     [[nodiscard]] virtual bool isPawn() const = 0;

     /**
     * Returns true or if the current piece is a knight
     * @return bool
     */
     [[nodiscard]] virtual bool isKnight() const = 0;

     /**
     * Returns true or if the current piece is a king
     * @return bool
     */
     [[nodiscard]] virtual bool isKing() const = 0;

     /**
      * If the piece is able to doubleMove, it will disable that. Otherwise, nothing will happen
      */
      virtual void doubleMoveDisable();
};


#endif //CPPESS_PIECE_H
