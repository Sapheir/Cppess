#include "gui/GUI.h"
#include "game/multiplayer/MultiplayerGameServer.h"
#include "game/multiplayer/MultiplayerGameClient.h"
#include <iostream>

void testConnection() {
    try {
        int option;
        std::cin >> option;
        if (option) {
            asio::io_context ioContext;
            MultiplayerGameServer server(ioContext, 12345);
            std::cout << "Server is running on " << server.getAddress() << "\n";
            ioContext.run();
        } else {
            asio::io_context ioContext;
            MultiplayerGameClient client(ioContext, "ip", "port");
            std::cout << "Client\n";
            ioContext.run();
        }

    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    try {
        GUI gui;
        gui.run();
    } catch (std::exception &exception) {
        std::cerr << exception.what() << "\n";
    }
    return 0;
}
