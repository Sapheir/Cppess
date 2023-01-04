// Created by Catalin
#pragma once
#include "../Game.h"
#include <asio.hpp>
#include <iostream>

using asio::ip::tcp;

class MultiplayerGameServer: public Game {
private:
    tcp::acceptor incomingConnectionAcceptor;
    std::unique_ptr<tcp::socket> connectedSocket;
    unsigned short port{};
    asio::streambuf readBuffer;

    /**
     * Initialize accepting a client's connection asynchronously
     */
    void startAcceptConnection();

    /**
     * Asynchronously read messages incoming from the client
     */
    void readMessage();

    /**
     * Does the client's input move
     * @param x Initial X coordinate
     * @param y Initial Y coordinate
     * @param newX Destination X coordinate
     * @param newY Destination Y coordinate
     */
    void moveOpponentPiece(const int &x, const int &y, const int &newX, const int &newY);

public:
    MultiplayerGameServer(asio::io_context &ioContext, const unsigned short &port, const colors &myColor);

    // TODO: send move struct/enum/dto whatever
    void sendMessage(const std::string &message);

    /**
     * @return The ip+port which can be used by the client to connect to the game
     */
    std::string getAddress();

    /**
     * Does the server owner's input move
     * @param x Initial X coordinate
     * @param y Initial Y coordinate
     * @param newX Destination X coordinate
     * @param newY Destination Y coordinate
     */
    void moveMyPiece(const int &x, const int &y, const int &newX, const int &newY);
};
