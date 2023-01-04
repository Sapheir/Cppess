// Created by Catalin
#pragma once
#include <asio.hpp>
#include <iostream>

using asio::ip::tcp;

class MultiplayerGameClient {
private:
    tcp::socket socket;
    asio::streambuf readBuffer;

    void connect(const std::string &ip, const std::string &port);
    void readMessage();

public:
    MultiplayerGameClient(asio::io_context &io_context, const std::string &ip, const std::string &port);
    void sendMessage(const std::string &message);
};
