//
// Created by User on 20/12/2022.
//

#ifndef CPPESS_SERVICETABLE_H
#define CPPESS_SERVICETABLE_H

#include <algorithm>
#include <string>
#include "../table/Table.h"
#include "../pieces/Piece.h"

class ServiceTable {
private:
    std::unique_ptr<Table> table;
public:

    ServiceTable() = delete;

    explicit ServiceTable(std::unique_ptr<Table> &table){
        this->table = std::move(table);
    };

    /**
     * Get the piece from chosen coordinates
     *
     * @param posX, posY: the coordinates
     * @return unique_ptr < Piece > piece: the piece from (posX, posY) if there is a piece
     *         nullptr if there is no piece on chosen coordinates
     */
    [[nodiscard]] std::shared_ptr < Piece > getPiece(const int &posX, const int &posY) const;

    /**
     * Move the piece from coordinates (x, y) to (newX, newY)
     * @param x - int
     * @param Y - int
     * @param posX - int
     * @param posY - int
     * @throw std::string errorMessage = "There is no piece on chosen position! " if there is no piece on (x, y)
     * @throw std::string errorMessage = "The move is not available! " if the player connot move the (x,y) piece
     * or (newX, newY) is not a valid destination
     */
    void movePiece(int x, int y, int newX, int newY);

    /**
     * Removes the piece from chosen coordinates and returns it
     * @param posX - int
     * @param posY  - int
     * @return - unique_ptr < Piece >
     *         - nullptr if there is no piece with chosen coordinates
     */
    std::shared_ptr < Piece > removePiece(const int &posX, const int &posY);

    /**
     * Add a new piece on table
     *
     * @param unique_ptr < Piece > newPiece: the piece we add on table
     */
    void addPiece(const std::shared_ptr<Piece>& newPiece);

    /**
     * Returns the list with all positions where the the piece from (posX, posY) can be moved
     * @param posX - int
     * @param posY - int
     * @return - vector < pair < int, int > >
     */
    [[nodiscard]] std::vector < std::pair < int, int > > availableMovesDestinations(const int &posX, const int &posY) const;


};


#endif //CPPESS_SERVICETABLE_H
