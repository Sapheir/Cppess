// Created by Catalin
#pragma once
#include "screens/Screen.h"
#include "screens/main_menu/MainMenu.h"
#include "screens/single_player/SinglePlayerOptions.h"
#include "screens/multiplayer/MultiplayerOptions.h"
#include "screens/screens.h"

#define FONT_SIZE 24

class GUI {
private:
    sf::RenderWindow window{sf::VideoMode{DEFAULT_WIDTH, DEFAULT_HEIGHT}, "Cppess",
                            sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize};
    sf::Font textFont;
    std::unique_ptr<Screen> currentScreen;
    screens currentScreenType;

    void loadFont();
    void loadIcon();
    void chooseScreen();

public:
    GUI();

    void run();
};
