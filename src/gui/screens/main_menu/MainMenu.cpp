// Created by Catalin
#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window, sf::Font& font, const unsigned int &fontSize, screens &nextScreen)
        : Screen{window, font, fontSize, nextScreen}, hoveredOption{single_player} {
    loadOptions();
    loadCursorSelect();
}

void MainMenu::loadOptions() {
    singlePlayerText = sf::Text{"Single player", font, fontSize};
    singlePlayerText.setFillColor(sf::Color::White);
    singlePlayerText.setOrigin((float)singlePlayerText.getLocalBounds().width / 2, (float)singlePlayerText.getLocalBounds().height / 2);
    singlePlayerText.setPosition(sf::Vector2f{(float)window.getSize().x / 2, (float)window.getSize().y / 2 - 100});

    multiplayerText = sf::Text{"Multiplayer", font, fontSize};
    multiplayerText.setFillColor(sf::Color::White);
    multiplayerText.setOrigin((float)multiplayerText.getLocalBounds().width / 2, (float)multiplayerText.getLocalBounds().height / 2);
    multiplayerText.setPosition(sf::Vector2f{(float)window.getSize().x / 2, (float)window.getSize().y / 2 - 50});

    quitText = sf::Text{"Quit", font, fontSize};
    quitText.setFillColor(sf::Color::White);
    quitText.setOrigin((float)quitText.getLocalBounds().width / 2, (float)quitText.getLocalBounds().height / 2);
    quitText.setPosition(sf::Vector2f{(float)window.getSize().x / 2, (float)window.getSize().y / 2});
}

void MainMenu::loadCursorSelect() {
    cursorSelect = sf::RectangleShape{sf::Vector2f{(float)window.getSize().x / 4, (float)window.getSize().y / 12}};
    cursorSelect.setFillColor(sf::Color(255, 255, 255, 100));
    cursorSelect.setOutlineThickness(2);
    cursorSelect.setOutlineColor(sf::Color::White);
    cursorSelect.setPosition(sf::Vector2f{(float)window.getSize().x / 2 - (float)cursorSelect.getSize().x / 2,
                                          singlePlayerText.getPosition().y - cursorSelect.getSize().y / 2});
}

void MainMenu::draw() {
    window.draw(singlePlayerText);
    window.draw(multiplayerText);
    window.draw(quitText);
    window.draw(cursorSelect);
}

void MainMenu::resize(const unsigned int &width, const unsigned int &height) {
    sf::FloatRect visibleArea{0, 0, (float)width, (float)height};
    window.setView(sf::View{visibleArea});

    sf::Vector2f newTextScale{(float)width / DEFAULT_WIDTH, (float)height / DEFAULT_HEIGHT};
    singlePlayerText.setScale(newTextScale);
    multiplayerText.setScale(newTextScale);
    quitText.setScale(newTextScale);
    float distanceScaled = 100 * (float)height / DEFAULT_HEIGHT;
    singlePlayerText.setPosition(sf::Vector2f{(float)width / 2, (float)height / 2 - distanceScaled});
    multiplayerText.setPosition(sf::Vector2f{(float)width / 2, (float)height / 2 - distanceScaled/2});
    quitText.setPosition(sf::Vector2f{(float)width / 2, (float)height / 2});

    cursorSelect.setSize(sf::Vector2f{(float)width / 4, (float)height / 12});
    cursorSelect.setPosition(sf::Vector2f{(float)width / 2 - (float)cursorSelect.getSize().x / 2,
                                          singlePlayerText.getPosition().y - cursorSelect.getSize().y / 2});
}

void MainMenu::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::MouseMoved) {
        setCursorSelectPosition(event.mouseMove.x, event.mouseMove.y);
    } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        switch (hoveredOption) {
            case single_player:
                nextScreen = single_player_options;
            case multiplayer:
                break;
            case quit:
                window.close();
                break;
        }
    }
}

void MainMenu::setCursorSelectPosition(const unsigned int &mouseMoveX, const unsigned int &mouseMoveY) {
    if (singlePlayerText.getGlobalBounds().contains(mouseMoveX, mouseMoveY)) {
        cursorSelect.setPosition(sf::Vector2f{cursorSelect.getPosition().x,
                                              singlePlayerText.getPosition().y - cursorSelect.getSize().y / 2});
        hoveredOption = single_player;
    } else if (multiplayerText.getGlobalBounds().contains(mouseMoveX, mouseMoveY)) {
        cursorSelect.setPosition(sf::Vector2f{cursorSelect.getPosition().x,
                                              multiplayerText.getPosition().y - cursorSelect.getSize().y / 2});
        hoveredOption = multiplayer;
    } else if (quitText.getGlobalBounds().contains(mouseMoveX, mouseMoveY)) {
        cursorSelect.setPosition(sf::Vector2f{cursorSelect.getPosition().x,
                                              quitText.getPosition().y - cursorSelect.getSize().y / 2});
        hoveredOption = quit;
    }
}

