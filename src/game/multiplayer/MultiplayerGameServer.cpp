// Created by Catalin
#include "MultiplayerGameServer.h"

MultiplayerGameServer::MultiplayerGameServer(asio::io_context &ioContext, const unsigned short &port)
                     : incomingConnectionAcceptor{ioContext, tcp::endpoint{tcp::v4(), port}}, port{port} {
    startAcceptConnection();
}

void MultiplayerGameServer::startAcceptConnection() {
    connectedSocket = std::make_unique<tcp::socket>(incomingConnectionAcceptor.get_executor());
    incomingConnectionAcceptor.async_accept(*connectedSocket, [this](const asio::error_code& error) {
        if (!error) {
            asio::ip::tcp::no_delay option(true);
            connectedSocket->set_option(option);
            readMessage();
        } else {
            std::cerr << error.message() << "\n";
        }
    });
}

void MultiplayerGameServer::readMessage() {
    asio::async_read_until(*connectedSocket, readBuffer, '\n',
                     [this](const asio::error_code& error, const std::size_t &bytesTransferred){
        if (!error) {
            // Print message from client
            std::cout << "Message from client: " << &readBuffer << "\n";
            readBuffer.consume(readBuffer.size());

            sendMessage("Hi client\n");
            // Wait for another message from client
            readMessage();
        }
        else {
            // Client disconnected, close socket
            connectedSocket->close();
        }
    });
}

void MultiplayerGameServer::sendMessage(const std::string &message) {
    asio::async_write(*connectedSocket, asio::buffer(message),
                      [](const asio::error_code& error, std::size_t bytes_transferred)
                      {
                          if (error)
                          {
                              std::cerr << error.message() << "\n";
                          }
                      });
}

std::string MultiplayerGameServer::getAddress() {
    tcp::resolver resolver(incomingConnectionAcceptor.get_executor());
    for (auto &it: resolver.resolve(asio::ip::host_name(), "")) {
        tcp::endpoint ed = it;
        if (ed.address().is_v4()) {
            return ed.address().to_string() + ":" + std::to_string(port);
        }
    }
    return "";
}
