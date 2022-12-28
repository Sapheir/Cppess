// Created by Catalin
#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "screens.h"

#define DEFAULT_WIDTH  800
#define DEFAULT_HEIGHT 600

class Screen {
protected:
    sf::RenderWindow& window;
    sf::Font& font;
    screens& nextScreen;
    unsigned int fontSize;

public:
    Screen(sf::RenderWindow& window, sf::Font& font, const unsigned int &fontSize, screens &nextScreen);
    virtual ~Screen() = default;
    virtual void draw() = 0;
    virtual void resize(const unsigned int &width, const unsigned int &height) = 0;
    virtual void handleEvent(sf::Event &event) = 0;
};
