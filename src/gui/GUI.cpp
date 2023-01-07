// Created by Catalin
#include "GUI.h"

GUI::GUI(): settings{white, ""} {
    loadFont();
    loadIcon();
    currentScreen = std::make_unique<MainMenu>(window, textFont, FONT_SIZE, currentScreenType);
}

void GUI::loadFont() {
    if (!textFont.loadFromFile("../assets/arial.ttf")) {
        throw std::runtime_error("Arial font was not found!");
    }
}

void GUI::loadIcon() {
    sf::Image icon;
    if (!icon.loadFromFile("../assets/icon.png")) {
        throw std::runtime_error("Icon was not found!");
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void GUI::run() {
    while (window.isOpen()) {
        sf::Event event{};
        screens initialType = currentScreenType;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    currentScreen->resize(event.size.width, event.size.height);
                    break;
                default:
                    currentScreen->handleEvent(event);
                    break;
            }
        }
        window.clear();
        if (currentScreenType != initialType) {
            chooseScreen();
        }
        currentScreen->draw();
        window.display();
    }
}

void GUI::chooseScreen() {
    switch (currentScreenType) {
        case main_menu:
            currentScreen = std::make_unique<MainMenu>(window, textFont, FONT_SIZE, currentScreenType);
            break;
        case single_player_options:
            currentScreen = std::make_unique<SinglePlayerOptions>(window, textFont, FONT_SIZE, currentScreenType, settings.color);
            break;
        case single_player_game:
            currentScreen = std::make_unique<SinglePlayer>(window, textFont, FONT_SIZE, currentScreenType, settings.color);
            break;
        case multiplayer_options:
            currentScreen = std::make_unique<MultiplayerOptions>(window, textFont, FONT_SIZE, currentScreenType, settings);
            break;
        case multiplayer_server:
            currentScreen = std::make_unique<MultiplayerServer>(window, textFont, FONT_SIZE, currentScreenType, settings);
            break;
        case multiplayer_client:
            currentScreen = std::make_unique<MultiplayerClient>(window, textFont, FONT_SIZE, currentScreenType, settings);
            break;
        default:
            currentScreen = std::make_unique<MainMenu>(window, textFont, FONT_SIZE, currentScreenType);
            break;
    }
}
