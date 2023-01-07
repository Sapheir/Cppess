// Created by Catalin
#pragma once
#include "../Game.h"
#include "message.h"
#include <asio.hpp>
#include <iostream>

using asio::ip::tcp;

class MultiplayerGameClient: public Game {
private:
    tcp::socket socket;
    asio::streambuf readBuffer;
    bool readServerColor{};

    /**
     * Asynchronously connect to a game server
     * @param address Address to connect to
     */
    void connect(const std::string &address);

    /**
     * Asynchronously read messages incoming from the server owner
     */
    void readMessage();

    /**
     * Does the server owner's input move
     * @param x Initial X coordinate
     * @param y Initial Y coordinate
     * @param newX Destination X coordinate
     * @param newY Destination Y coordinate
     */
    void moveOpponentPiece(const int &x, const int &y, const int &newX, const int &newY);

public:
    MultiplayerGameClient(asio::io_context &io_context, const std::string &address, const colors &myColor);
    void sendMessage(const std::string &message);

    /**
     * Does the client's input move
     * @param x Initial X coordinate
     * @param y Initial Y coordinate
     * @param newX Destination X coordinate
     * @param newY Destination Y coordinate
     */
    void moveMyPiece(const int &x, const int &y, const int &newX, const int &newY);
};
