// Created by Catalin
#include "MultiplayerGameClient.h"

MultiplayerGameClient::MultiplayerGameClient(asio::io_context &ioContext, const std::string &address, const colors &myColor)
        : Game{myColor}, socket{ioContext} {
    connect(address);
}

void MultiplayerGameClient::connect(const std::string &address) {
    unsigned int semiColPos = address.find(':');
    std::string ip = address.substr(0, semiColPos), port = address.substr(semiColPos+1);
    tcp::resolver resolver(socket.get_executor());
    asio::connect(socket, resolver.resolve(ip, port));
    asio::ip::tcp::no_delay option(true);
    socket.set_option(option);
    readMessage();
}

void MultiplayerGameClient::sendMessage(const std::string &message) {
    asio::async_write(socket, asio::buffer(message),
                      [](const asio::error_code& error, std::size_t bytes_transferred) {
                          if (error) {
                              std::cerr << error.message() << "\n";
                          }
                      });
}

void MultiplayerGameClient::readMessage() {
    asio::async_read_until(socket, readBuffer, '\n',
                     [this](const asio::error_code& error, const std::size_t &bytesTransferred){
                         if (!error) {
                             std::istream is(&readBuffer);
                             if (!readServerColor) {
                                 std::string color;
                                 std::getline(is, color);
                                 if (color == std::to_string(myColor))
                                     std::cerr << "Same pieces color as the server owner\n";
                                 readServerColor = true;
                             } else {
                                 move move;
                                 is >> move;
                                 std::cout << "Message from server: " << &readBuffer << "\n";
                             }
                             readBuffer.consume(readBuffer.size());
                             readMessage();
                         }
                         else {
                             // Server disconnected, close socket
                             socket.close();
                         }
                     });
}

void MultiplayerGameClient::moveOpponentPiece(const int &x, const int &y, const int &newX, const int &newY) {
    if (isGameOver)
        return;
    std::cout << "Opponent's move\n";
    auto events = movePiece(x, y, newX, newY);
    for (auto &pieceInfo: currentPiecesInfo) {
        if (pieceInfo.posX == x && pieceInfo.posY == y) {
            pieceInfo.posX = newX;
            pieceInfo.posY = newY;
            break;
        }
    }
    handleMovePieceEvents(events, newX, newY, true);
}

void MultiplayerGameClient::moveMyPiece(const int &x, const int &y, const int &newX, const int &newY) {
    if (isGameOver)
        return;
    std::cout << "Your move\n";
    auto events = movePiece(x, y, newX, newY);
    for (auto &pieceInfo: currentPiecesInfo) {
        if (pieceInfo.posX == x && pieceInfo.posY == y) {
            pieceInfo.posX = newX;
            pieceInfo.posY = newY;
            break;
        }
    }
    handleMovePieceEvents(events, newX, newY, true);
}
