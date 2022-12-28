// Created by Catalin
#pragma once
#include <SFML/Graphics.hpp>

#define DEFAULT_WIDTH  800
#define DEFAULT_HEIGHT 600

class GUI {
private:
    sf::RenderWindow window{sf::VideoMode{DEFAULT_WIDTH, DEFAULT_HEIGHT}, "Cppess",
                            sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize};
    sf::Font textFont;

    void loadFont();
    void loadIcon();
    void loadMainMenu();

public:
    GUI();

    void run();
};
