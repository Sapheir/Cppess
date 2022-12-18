//
// Created by Turca Vasile on 27/09/2022.
//

#ifndef CPPESS_TABLE_H
#define CPPESS_TABLE_H

#include <vector>
#include <memory>
#include "../pieces/Piece.h"

class Table {
private:
    int tableSize;
    std:: vector < std::shared_ptr < Piece > > tableContent;
public:

    Table() = delete;

    /**
     * Create a table with size tableSize x tableSize
     */
    explicit Table(int tableSize);

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
    void addPiece(std::shared_ptr<Piece> newPiece);

    /**
     * Get the piece from chosen coordinates
     *
     * @param posX, posY: the coordinates
     * @return unique_ptr < Piece > piece: the piece from (posX, posY) if there is a piece
     *         nullptr if there is no piece on chosen coordinates
     */
    std::shared_ptr < Piece > getPiece(const int &posX, const int &posY);

    /**
     * Removes the piece from chosen coordinates and returns it
     * @param posX - int
     * @param posY  - int
     * @return - unique_ptr < Piece >
     *         - nullptr if there is no piece with chosen coordinates
     */
    std::shared_ptr < Piece > removePiece(const int &posX, const int &posY);

    

    ~Table() = default;

};

#endif //CPPESS_TABLE_H
