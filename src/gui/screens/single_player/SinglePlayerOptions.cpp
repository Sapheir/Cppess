// Created by Catalin
#include <iostream>
#include "SinglePlayerOptions.h"

SinglePlayerOptions::SinglePlayerOptions(sf::RenderWindow& window, sf::Font& font, const unsigned int &fontSize, screens &nextScreen)
        : Screen{window, font, fontSize, nextScreen}, selectedColor{white}, hoveredColor{white} {
    loadOptions();
    loadCursorSelections();
}

void SinglePlayerOptions::loadOptions() {
    colorLabel = sf::Text{"Choose your color:", font, fontSize};
    colorLabel.setFillColor(sf::Color::White);
    colorLabel.setStyle(sf::Text::Bold);
    colorLabel.setOrigin((float)colorLabel.getLocalBounds().width / 2, (float)colorLabel.getLocalBounds().height / 2);
    colorLabel.setPosition((float)window.getSize().x / 2, (float)window.getSize().y / 2 - 100);

    chooseWhite = sf::Text{"White", font, fontSize};
    chooseWhite.setFillColor(sf::Color::White);
    chooseWhite.setOrigin((float)chooseWhite.getLocalBounds().width / 2, (float)chooseWhite.getLocalBounds().height / 2);
    chooseWhite.setPosition((float)window.getSize().x / 2 - 100, (float)window.getSize().y / 2 - 50);

    chooseBlack = sf::Text{"Black", font, fontSize};
    chooseBlack.setFillColor(sf::Color::White);
    chooseBlack.setOrigin((float)chooseBlack.getLocalBounds().width / 2, (float)chooseBlack.getLocalBounds().height / 2);
    chooseBlack.setPosition((float)window.getSize().x / 2 + 100, (float)window.getSize().y / 2 - 50);

    playLabel = sf::Text{"Play", font, fontSize};
    playLabel.setFillColor(sf::Color::White);
    playLabel.setStyle(sf::Text::Bold);
    playLabel.setOrigin((float)playLabel.getLocalBounds().width / 2, (float)playLabel.getLocalBounds().height / 2);
    playLabel.setPosition((float)window.getSize().x / 2, (float)window.getSize().y / 2);
}

void SinglePlayerOptions::loadCursorSelections() {
    selectedOption = sf::RectangleShape{sf::Vector2f{(float)window.getSize().x / 4, (float)window.getSize().y / 12}};
    selectedOption.setFillColor(sf::Color(255, 255, 255, 100));
    selectedOption.setOutlineThickness(2);
    selectedOption.setOutlineColor(sf::Color::Red);
    selectedOption.setPosition(sf::Vector2f{(float)chooseWhite.getPosition().x - (float)selectedOption.getSize().x / 2,
                                            chooseWhite.getPosition().y - selectedOption.getSize().y / 2});

    hoveredOption = sf::RectangleShape{sf::Vector2f{(float)window.getSize().x / 4, (float)window.getSize().y / 12}};
    hoveredOption.setFillColor(sf::Color(255, 255, 255, 100));
    hoveredOption.setOutlineThickness(2);
    hoveredOption.setOutlineColor(sf::Color::White);
    hoveredOption.setPosition(sf::Vector2f{(float)chooseWhite.getPosition().x - (float)hoveredOption.getSize().x / 2,
                                            chooseWhite.getPosition().y - hoveredOption.getSize().y / 2});
}

void SinglePlayerOptions::draw() {
    window.draw(colorLabel);
    window.draw(chooseWhite);
    window.draw(chooseBlack);
    window.draw(playLabel);
    window.draw(hoveredOption);
    window.draw(selectedOption);
}

void SinglePlayerOptions::resize(const unsigned int &width, const unsigned int &height) {
    sf::FloatRect visibleArea{0, 0, (float)width, (float)height};
    window.setView(sf::View{visibleArea});

    sf::Vector2f newTextScale{(float)width / DEFAULT_WIDTH, (float)height / DEFAULT_HEIGHT};
    colorLabel.setScale(newTextScale);
    chooseWhite.setScale(newTextScale);
    chooseBlack.setScale(newTextScale);
    playLabel.setScale(newTextScale);
    float distanceScaled = 100 * (float)height / DEFAULT_HEIGHT;
    colorLabel.setPosition(sf::Vector2f{(float)width / 2, (float)height / 2 - distanceScaled});
    chooseWhite.setPosition(sf::Vector2f{(float)width / 2 - distanceScaled, (float)height / 2 - distanceScaled / 2});
    chooseBlack.setPosition(sf::Vector2f{(float)width / 2 + distanceScaled, (float)height / 2 - distanceScaled / 2});
    playLabel.setPosition(sf::Vector2f{(float)width / 2, (float)height / 2});

    hoveredOption.setSize(sf::Vector2f{(float)width / 4, (float)height / 12});
    hoveredOption.setPosition(sf::Vector2f{chooseWhite.getPosition().x - hoveredOption.getSize().x / 2,
                                           chooseWhite.getPosition().y - hoveredOption.getSize().y / 2});

    selectedOption.setSize(sf::Vector2f{(float)width / 4, (float)height / 12});
    if (hoveredColor == white) {
        selectedOption.setPosition(sf::Vector2f{chooseWhite.getPosition().x - selectedOption.getSize().x / 2,
                                                chooseWhite.getPosition().y - selectedOption.getSize().y / 2});
    } else {
        selectedOption.setPosition(sf::Vector2f{chooseBlack.getPosition().x - selectedOption.getSize().x / 2,
                                                chooseBlack.getPosition().y - selectedOption.getSize().y / 2});
    }
}

void SinglePlayerOptions::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::MouseMoved) {
        setCursorHoverPosition(event.mouseMove.x, event.mouseMove.y);
    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        nextScreen = main_menu;
    } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        handleClick(event.mouseButton.x, event.mouseButton.y);
    }
}

void SinglePlayerOptions::setCursorHoverPosition(const unsigned int &mouseMoveX, const unsigned int &mouseMoveY) {

    if (chooseWhite.getGlobalBounds().contains(mouseMoveX, mouseMoveY)) {
        hoveredOption.setPosition(sf::Vector2f{chooseWhite.getPosition().x - hoveredOption.getSize().x / 2,
                                                chooseWhite.getPosition().y - hoveredOption.getSize().y / 2});
        hoveredColor = white;
    } else if (chooseBlack.getGlobalBounds().contains(mouseMoveX, mouseMoveY)) {
        hoveredOption.setPosition(sf::Vector2f{chooseBlack.getPosition().x - hoveredOption.getSize().x / 2,
                                                chooseBlack.getPosition().y - hoveredOption.getSize().y / 2});
        hoveredColor = black;
    } else if (playLabel.getGlobalBounds().contains(mouseMoveX, mouseMoveY)) {
        hoveredOption.setPosition(sf::Vector2f{playLabel.getPosition().x - hoveredOption.getSize().x / 2,
                                               playLabel.getPosition().y - hoveredOption.getSize().y / 2});
    }
}

void SinglePlayerOptions::handleClick(const unsigned int &mouseButtonX, const unsigned int &mouseButtonY) {
    if (playLabel.getGlobalBounds().contains(mouseButtonX, mouseButtonY)) {
        std::cout << "Play\n";
    } else if (hoveredColor == white) {
        selectedOption.setPosition(sf::Vector2f{chooseWhite.getPosition().x - selectedOption.getSize().x / 2,
                                                chooseWhite.getPosition().y - selectedOption.getSize().y / 2});
    } else {
        selectedOption.setPosition(sf::Vector2f{chooseBlack.getPosition().x - selectedOption.getSize().x / 2,
                                                chooseBlack.getPosition().y - selectedOption.getSize().y / 2});
    }
}

