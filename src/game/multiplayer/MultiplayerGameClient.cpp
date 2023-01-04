// Created by Catalin
#include "MultiplayerGameClient.h"

MultiplayerGameClient::MultiplayerGameClient(asio::io_context &ioContext, const std::string &ip, const std::string &port)
        : socket{ioContext} {
    connect(ip, port);
}

void MultiplayerGameClient::connect(const std::string &ip, const std::string &port) {
    tcp::resolver resolver(socket.get_executor());
    asio::connect(socket, resolver.resolve(ip, port));
    asio::ip::tcp::no_delay option(true);
    socket.set_option(option);

    // Send message to server
    sendMessage("Hello, server!\n");
    readMessage();
}

void MultiplayerGameClient::sendMessage(const std::string &message) {
    asio::async_write(socket, asio::buffer(message),
                      [](const asio::error_code& error, std::size_t bytes_transferred)
                      {
                          if (error)
                          {
                              std::cerr << error.message() << "\n";
                          }
                      });
}

void MultiplayerGameClient::readMessage() {
    asio::async_read_until(socket, readBuffer, '\n',
                     [this](const asio::error_code& error, const std::size_t &bytesTransferred){
                         if (!error) {
                             // Print message from server
                             std::cout << "Message from server: " << &readBuffer << "\n";
                             readBuffer.consume(readBuffer.size());
                             // Wait for another message from server
                             readMessage();
                         }
                         else {
                             // Server disconnected, close socket
                             socket.close();
                         }
                     });
}
