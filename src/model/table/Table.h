//
// Created by Turca Vasile on 27/09/2022.
//

#ifndef CPPESS_TABLE_H
#define CPPESS_TABLE_H

#include <vector>
#include <memory>
#include <map>
#include "../domain/pieces/Piece.h"

class Table {
private:
    int tableSize;
    std:: map < std::pair < int, int >, std::shared_ptr < Piece > > tableContent;

public:

    Table() = delete;

    /**
     * Returns true if there is no piece between (x1, y1) and (x2, y2) and false otherwise
     * @param x1 - int
     * @param y1 - int
     * @param x2 - int
     * @param y2 - int
     * @return bool
     */
    [[nodiscard]] bool noPieceBetween(int x1, int y1, int x2, int y2) const;

    /**
     * Create a table with size tableSize x tableSize
     */
    explicit Table(int tableSize);

    /**
     * Move the piece on a valid destination
     * @param piece - Piece
     * @param (newX, newY) - (int, int) - new destination
     */
    void movePieceOnValidDestination(std::shared_ptr<Piece> piece, int newX, int newY);

    /**
     * Return the size of the table
     *
     * @return table size as an int
     */
    [[nodiscard]] int getTableSize() const;

    /**
     * Add a new piece on table
     *
     * @param unique_ptr < Piece > newPiece: the piece we add on table
     */
    void addPiece(const std::shared_ptr<Piece>& newPiece);

    /**
     * Get the piece from chosen coordinates
     *
     * @param posX, posY: the coordinates
     * @return unique_ptr < Piece > piece: the piece from (posX, posY) if there is a piece
     *         nullptr if there is no piece on chosen coordinates
     */
    [[nodiscard]] std::shared_ptr < Piece > getPiece(const int &posX, const int &posY) const;

    /**
     * Removes the piece from chosen coordinates and returns it
     * @param posX - int
     * @param posY  - int
     * @return - unique_ptr < Piece >
     *         - nullptr if there is no piece with chosen coordinates
     */
    std::shared_ptr < Piece > removePiece(const int &posX, const int &posY);

    /**
     * Returns all available moves for a pawn
     * @param piece - the pawn we want next moves
     * @return vector < pair < int, int > >
     */
    [[nodiscard]] std::vector < std::pair < int, int > > availableMovesDestinationsPawn(const std::shared_ptr<Piece> &piece) const;

    /**
     * Returns all available moves for a knight
     * @param piece - the knight we want next moves
     * @return vector < pair < int, int > >
     */
    [[nodiscard]] std::vector < std::pair < int, int > > availableMovesDestinationsKnight(const std::shared_ptr<Piece> &piece) const;

    /**
     * Returns all available moves for a knight
     * @param piece - the knight we want next moves
     * @return vector < pair < int, int > >
     */
    [[nodiscard]] std::vector < std::pair < int, int > > availableMovesDestinationsNonKnightOrPawn(const std::shared_ptr<Piece> &piece) const;

    /**
     * Returns the list with all positions where the the piece from (posX, posY) can be moved
     * @param posX - int
     * @param posY - int
     * @return - vector < pair < int, int > >
     */
    [[nodiscard]] std::vector < std::pair < int, int > > availableMovesDestinations(const int &posX, const int &posY) const;

    /**
     * Returns the list with all positions where the the piece from (posX, posY) can be moved
     * @param - Piece
     * @return - vector < pair < int, int > >
     */
    [[nodiscard]] std::vector < std::pair < int, int > > availableMovesDestinations(const std::shared_ptr<Piece> &piece) const;

    /**
     * Returns true if the current piece has crossed the table
     * @param - Piece reference
     */
     [[nodiscard]]  bool pieceWillBeOnOppositeEdge(const int &newX, const int &newY) const;

     /**
     * Returns the king with the current color
     * @param color - colors - the color we want
     * @return - std::shared_ptr < Piece >
     */
     [[nodiscard]] std::shared_ptr < Piece > getKing(colors color) const;

     /**
      * Returns if a king is under attack
      * @param color -colors - color of the king we want to check
      * @return bool
      */
     [[nodiscard]] bool kingUnderAttack(colors color) const;

     /**
      * Returns if a piece is under attack
      * @param (x, y) - (int, int)
      * @return std::vector < std::pair < int, int > > - all attackers
      */
      [[nodiscard]] std::vector < std::pair < int, int > > underAttack(const int &x, const int &y) const;

    ~Table() = default;

};

#endif //CPPESS_TABLE_H
