// Created by Catalin
#pragma once
#include "../Screen.h"
#include "./main_menu_options.h"

class MainMenu: public Screen {
private:
    sf::Text singlePlayerText, multiplayerText, quitText;
    sf::RectangleShape cursorSelect;
    main_menu_options hoveredOption;
    void loadOptions();
    void loadCursorSelect();
    void setCursorSelectPosition(const unsigned int &mouseMoveX, const unsigned int &mouseMoveY);

public:
    MainMenu(sf::RenderWindow& window, sf::Font& font, const unsigned int &fontSize);
    void draw() override;
    void resize(const unsigned int &width, const unsigned int &height) override;
    void handleEvent(sf::Event &event) override;
};
