// Created by Catalin
#pragma once
#include <asio.hpp>
#include <iostream>

using asio::ip::tcp;

class MultiplayerGameServer {
private:
    tcp::acceptor incomingConnectionAcceptor;
    std::unique_ptr<tcp::socket> connectedSocket;
    unsigned short port{};
    asio::streambuf readBuffer;
    void startAcceptConnection();
    void readMessage();

public:
    MultiplayerGameServer(asio::io_context &ioContext, const unsigned short &port);
    void sendMessage(const std::string &message);
    std::string getAddress();
};
