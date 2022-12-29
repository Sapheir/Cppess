// Created by Catalin
#pragma once
#include "../Screen.h"
#include "../../../model/pieces/colors.h"

class MultiplayerOptions: public Screen {
private:
    sf::Text colorLabel, chooseBlack, chooseWhite, createLabel, inputLabel, inputForm, joinLabel;
    sf::RectangleShape hoveredOption, selectedOption, inputCursor;
    colors selectedColor, hoveredColor;
    std::string joinText;
    unsigned int cursorPosition{};
    void loadOptions();
    void loadCursorSelections();
    void setCursorHoverPosition(const unsigned int &mouseMoveX, const unsigned int &mouseMoveY);
    void handleClick(const unsigned int &mouseButtonX, const unsigned int &mouseButtonY);

public:
    MultiplayerOptions(sf::RenderWindow& window, sf::Font& font, const unsigned int &fontSize, screens &nextScreen);
    void draw() override;
    void resize(const unsigned int &width, const unsigned int &height) override;
    void handleEvent(sf::Event &event) override;
};
