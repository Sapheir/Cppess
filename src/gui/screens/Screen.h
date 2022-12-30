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

    /**
     * Method used to draw the screen and its components
     */
    virtual void draw() = 0;

    /**
     * Method used to resize the current screen
     * @param width new width after resize
     * @param height new height after resize
     */
    virtual void resize(const unsigned int &width, const unsigned int &height) = 0;

    /**
     * Method used to handle events given by user interactions with the screen
     * @param event the event which was input by the user
     */
    virtual void handleEvent(sf::Event &event) = 0;
};
