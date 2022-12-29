//
// Created by Turca Vasile
//

#ifndef CPPESS_SERVICETABLE_H
#define CPPESS_SERVICETABLE_H

#include <algorithm>
#include <string>
#include "../table/Table.h"
#include "../domain/pieces/Piece.h"
#include "../domain/Events.h"
#include "../table/History.h"

class ServiceTable {
private:
    std::unique_ptr<Table> table;
    colors firstPlayerColor;
    colors secondPlayerColor;
    colors currentPlayer;
    std::vector < std::shared_ptr < HistoryMove > > history;

    /**
     * Change the player whose turn is now
     */
    void changeTurn();

    /**
     * Add current move int the history
     * @param (x, y) - (int, int) - the old position of the moved piece
     * @param (newX, newY) - (int, int ) - the new position of the moved piece
     * @param piece - std::shared_ptr < Piece > - moved piece;
     */
    void addInHistory(const int &x, const int &y, const int &newX, const int &newY, const std::shared_ptr < Piece > &piece);

    /**
     * Returns the reference to the king of current color
     * @return
     */
    [[nodiscard]] std::shared_ptr < Piece > getKing() const;

public:

    ServiceTable() = delete;

    explicit ServiceTable(std::unique_ptr<Table> &table, colors firstPlayerColor, colors secondPlayerColor){
        this->table = std::move(table);
        this->firstPlayerColor = firstPlayerColor;
        this->secondPlayerColor = secondPlayerColor;
        currentPlayer = firstPlayerColor;
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

    /**
     * Check if the piece can be moved from coordinates (x, y) to (newX, newY)
     * @param x - int
     * @param Y - int
     * @param posX - int
     * @param posY - int
     * @throw std::string errorMessage = "There is no piece on chosen position! " if there is no piece on (x, y)
     * @throw std::string errorMessage = "The move is not available! " if the player connot move the (x,y) piece
     * or (newX, newY) is not a valid destination
     * @throw std::string errorMessage = "The move is not available because you left the king without guard! " if the king
     * get into opponent next possible moves
     * @throw std:: string errorMessage = "You cannot move the pieces of the opponent! " - if you want to move a piece
     * of the opponent
     */
     void checkMoveAvailable(const int &x, const int &y, const int &newX, const int &newY) const;

    /**
     * Move the piece from coordinates (x, y) to (newX, newY)
     * @param x - int
     * @param Y - int
     * @param posX - int
     * @param posY - int
     * @return - std::vector < std::shared_ptr < BaseEvent > > the list of the Events generated by the current move
     * @throw std::string errorMessage = "There is no piece on chosen position! " if there is no piece on (x, y)
     * @throw std::string errorMessage = "The move is not available! " if the player connot move the (x,y) piece
     * or (newX, newY) is not a valid destination
     * @throw std::string errorMessage = "The move is not available because you left the king without guard! " if the king
     * get into opponent next possible moves
     * @throw std:: string errorMessage = "You cannot move the pieces of the opponent! " - if you want to move a piece
     * of the opponent
     */
    std::vector < std::shared_ptr < BaseEvent > > movePiece(const int &x, const int &y, const int &newX, const int &newY);

    /**
     * Returns all special Events created by moving the piece into the chosen coordinates
     * @param (newX, newY) - (int, int) - the position where will be the piece moved
     * @param piece - Piece
     * @return std::vector < std::shared_ptr < BaseEvent > > - all events generated by the next move
     */
    std::vector < std::shared_ptr < BaseEvent > > getSpecialEvents(const std::shared_ptr < Piece > &piece,
                                                                   const int &newX, const int &newY);

    /**
     * Returns true if the current piece is eligible for pawn promotion
     * @param (newX, newY) - (int, int) - the position where will be the piece moved
     * @param piece - Piece
     * @return bool
     */
    [[nodiscard]] bool checkPawnPromotion(const std::shared_ptr<Piece> &piece, const int &newX, const int &newY) const;

    /**
     * Returns true if the current move represents en_passant
     * @param (newX, newY) - (int, int) - the position where will be the piece moved
     * @param piece - Piece
     * @return bool
     */
     [[nodiscard]] bool checkEnPassant(const std::shared_ptr<Piece> &piece, const int &newX, const int &newY) const;

     /**
      * Returns the last move from history
      * @return HistoryMove
      */
     [[nodiscard]] std::shared_ptr < HistoryMove > getLastMoveFromHistory() const;

     /**
      * Returns true if the king is unprotected ( can be under attack of some enemy piece)
      * @return bool
      */
      [[nodiscard]] bool kingUnprotected();

      /**
       * Check if the opponent king is under attack from some piece
       * @return std::vector < std::shared_ptr < BaseEvent > > - vector with attack events
       */
      [[nodiscard]] std::vector < std::shared_ptr < BaseEvent > > checkIfTheOpponentKingIsUnderAttack() const;

      /**
       * Add in last history records if the opponent king gets under attack after current move
       */
       void addOpponentKingUnderAttackInHistory();

};


#endif //CPPESS_SERVICETABLE_H
