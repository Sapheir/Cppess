// Created by Catalin
#pragma once
#include "../Game.h"
#include <asio.hpp>
#include <iostream>

using asio::ip::tcp;

class MultiplayerGameClient: public Game {
private:
    tcp::socket socket;
    asio::streambuf readBuffer;

    /**
     * Asynchronously connect to a game server
     * @param ip Ip of the server
     * @param port Port of the server
     */
    void connect(const std::string &ip, const std::string &port);

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
    MultiplayerGameClient(asio::io_context &io_context, const std::string &ip, const std::string &port, const colors &myColor);
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
