// Created by Catalin
#pragma once
#include "screens/Screen.h"
#include "screens/main_menu/MainMenu.h"

class GUI {
private:
    sf::RenderWindow window{sf::VideoMode{DEFAULT_WIDTH, DEFAULT_HEIGHT}, "Cppess",
                            sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize};
    sf::Font textFont;
    std::unique_ptr<Screen> currentScreen;

    void loadFont();
    void loadIcon();

public:
    GUI();

    void run();
};
