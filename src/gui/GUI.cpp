// Created by Catalin
#include "GUI.h"

GUI::GUI() {
    loadFont();
    loadIcon();
    currentScreen = std::make_unique<MainMenu>(window, textFont, 24);
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
        currentScreen->draw();
        window.display();
    }
}
