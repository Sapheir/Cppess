// Created by Catalin
#include <iostream>
#include "MultiplayerOptions.h"

MultiplayerOptions::MultiplayerOptions(sf::RenderWindow& window, sf::Font& font, const unsigned int &fontSize, screens &nextScreen, settings &settings)
        : Screen{window, font, fontSize, nextScreen}, hoveredColor{white}, selectedSettings{settings} {
    loadOptions();
    loadCursorSelections();
}

void MultiplayerOptions::loadOptions() {
    colorLabel = sf::Text{"Choose your color:", font, fontSize};
    colorLabel.setFillColor(sf::Color::White);
    colorLabel.setStyle(sf::Text::Bold);
    colorLabel.setOrigin((float)colorLabel.getLocalBounds().width / 2, (float)colorLabel.getLocalBounds().height / 2);
    colorLabel.setPosition((float)window.getSize().x / 2, (float)window.getSize().y / 2 - 150);

    chooseWhite = sf::Text{"White", font, fontSize};
    chooseWhite.setFillColor(sf::Color::White);
    chooseWhite.setOrigin((float)chooseWhite.getLocalBounds().width / 2, (float)chooseWhite.getLocalBounds().height / 2);
    chooseWhite.setPosition((float)window.getSize().x / 2 - 100, (float)window.getSize().y / 2 - 100);

    chooseBlack = sf::Text{"Black", font, fontSize};
    chooseBlack.setFillColor(sf::Color::White);
    chooseBlack.setOrigin((float)chooseBlack.getLocalBounds().width / 2, (float)chooseBlack.getLocalBounds().height / 2);
    chooseBlack.setPosition((float)window.getSize().x / 2 + 100, (float)window.getSize().y / 2 - 100);

    createLabel = sf::Text{"Create game", font, fontSize};
    createLabel.setFillColor(sf::Color::White);
    createLabel.setStyle(sf::Text::Bold);
    createLabel.setOrigin((float)createLabel.getLocalBounds().width / 2, (float)createLabel.getLocalBounds().height / 2);
    createLabel.setPosition((float)window.getSize().x / 2, (float)window.getSize().y / 2 - 50);

    inputLabel = sf::Text{"Enter server ip:", font, fontSize};
    inputLabel.setFillColor(sf::Color::White);
    inputLabel.setStyle(sf::Text::Bold);
    inputLabel.setOrigin((float)inputLabel.getLocalBounds().width / 2, (float)inputLabel.getLocalBounds().height / 2);
    inputLabel.setPosition((float)window.getSize().x / 2, (float)window.getSize().y / 2);

    inputForm = sf::Text{"", font, fontSize};
    inputForm.setFillColor(sf::Color::White);
    inputForm.setOrigin((float)inputForm.getLocalBounds().width / 2, (float)inputForm.getLocalBounds().height / 2);
    inputForm.setPosition((float)window.getSize().x / 2, (float)window.getSize().y / 2 + 50);
    inputCursor = sf::RectangleShape{sf::Vector2f{1, (float)fontSize}};
    inputCursor.setFillColor(sf::Color::Red);
    inputCursor.setPosition(inputForm.findCharacterPos(cursorPosition));

    joinLabel = sf::Text{"Join", font, fontSize};
    joinLabel.setFillColor(sf::Color::White);
    joinLabel.setStyle(sf::Text::Bold);
    joinLabel.setOrigin((float)joinLabel.getLocalBounds().width / 2, (float)joinLabel.getLocalBounds().height / 2);
    joinLabel.setPosition((float)window.getSize().x / 2, (float)window.getSize().y / 2 + 100);
}

void MultiplayerOptions::loadCursorSelections() {
    selectedSettings.color = white;
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

void MultiplayerOptions::draw() {
    window.draw(colorLabel);
    window.draw(chooseWhite);
    window.draw(chooseBlack);
    window.draw(createLabel);
    window.draw(hoveredOption);
    window.draw(selectedOption);
    window.draw(inputLabel);
    window.draw(inputForm);
    window.draw(joinLabel);
    static sf::Clock clock;
    if (clock.getElapsedTime().asSeconds() > 0.5f) {
        window.draw(inputCursor);
    }
    if (clock.getElapsedTime().asSeconds() > 1.0f) {
        clock.restart();
    }
}

void MultiplayerOptions::resize(const unsigned int &width, const unsigned int &height) {
    sf::FloatRect visibleArea{0, 0, (float)width, (float)height};
    window.setView(sf::View{visibleArea});

    sf::Vector2f newTextScale{(float)width / DEFAULT_WIDTH, (float)height / DEFAULT_HEIGHT};
    colorLabel.setScale(newTextScale);
    chooseWhite.setScale(newTextScale);
    chooseBlack.setScale(newTextScale);
    createLabel.setScale(newTextScale);
    inputLabel.setScale(newTextScale);
    inputForm.setScale(newTextScale);
    joinLabel.setScale(newTextScale);
    float distanceScaled = 100 * (float)height / DEFAULT_HEIGHT;
    colorLabel.setPosition(sf::Vector2f{(float)width / 2, (float)height / 2 - 3 * distanceScaled / 2});
    chooseWhite.setPosition(sf::Vector2f{(float)width / 2 - distanceScaled, (float)height / 2 - distanceScaled});
    chooseBlack.setPosition(sf::Vector2f{(float)width / 2 + distanceScaled, (float)height / 2 - distanceScaled});
    createLabel.setPosition(sf::Vector2f{(float)width / 2, (float)height / 2 - distanceScaled / 2});
    inputLabel.setPosition(sf::Vector2f{(float)width / 2, (float)height / 2});
    inputForm.setPosition(sf::Vector2f{(float)width / 2, (float)height / 2 + distanceScaled / 2});
    joinLabel.setPosition(sf::Vector2f{(float)width / 2, (float)height / 2 + distanceScaled});
    inputCursor.setSize(sf::Vector2f{1, (float)fontSize*(float)height/DEFAULT_HEIGHT});
    inputCursor.setPosition(inputForm.findCharacterPos(cursorPosition));

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

void MultiplayerOptions::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::MouseMoved) {
        setCursorHoverPosition(event.mouseMove.x, event.mouseMove.y);
    } else if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode >= 32 && event.text.unicode <= 126 && selectedSettings.joinString.size() < 40) {
            selectedSettings.joinString.insert(cursorPosition, 1, (char)event.text.unicode);
            cursorPosition++;
        }
    } else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            nextScreen = main_menu;
        }
        if (event.key.code == sf::Keyboard::BackSpace && cursorPosition > 0) {
            selectedSettings.joinString.erase(cursorPosition - 1, 1);
            cursorPosition--;
        }
        if (event.key.code == sf::Keyboard::Delete && cursorPosition < selectedSettings.joinString.size()) {
            selectedSettings.joinString.erase(cursorPosition, 1);
        }
        if (event.key.code == sf::Keyboard::Left && cursorPosition > 0) {
            cursorPosition--;
        }
        if (event.key.code == sf::Keyboard::Right && cursorPosition < selectedSettings.joinString.size()) {
            cursorPosition++;
        }
    } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        handleClick(event.mouseButton.x, event.mouseButton.y);
    }
    inputForm.setString(selectedSettings.joinString);
    inputForm.setOrigin((float)inputForm.getLocalBounds().width / 2, (float)inputForm.getLocalBounds().height / 2);
    inputForm.setPosition((float)window.getSize().x / 2, (float)window.getSize().y / 2 + 50);
    inputCursor.setPosition(inputForm.findCharacterPos(cursorPosition));
}

void MultiplayerOptions::setCursorHoverPosition(const unsigned int &mouseMoveX, const unsigned int &mouseMoveY) {

    if (chooseWhite.getGlobalBounds().contains(mouseMoveX, mouseMoveY)) {
        hoveredOption.setPosition(sf::Vector2f{chooseWhite.getPosition().x - hoveredOption.getSize().x / 2,
                                               chooseWhite.getPosition().y - hoveredOption.getSize().y / 2});
        hoveredColor = white;
    } else if (chooseBlack.getGlobalBounds().contains(mouseMoveX, mouseMoveY)) {
        hoveredOption.setPosition(sf::Vector2f{chooseBlack.getPosition().x - hoveredOption.getSize().x / 2,
                                               chooseBlack.getPosition().y - hoveredOption.getSize().y / 2});
        hoveredColor = black;
    } else if (createLabel.getGlobalBounds().contains(mouseMoveX, mouseMoveY)) {
        hoveredOption.setPosition(sf::Vector2f{createLabel.getPosition().x - hoveredOption.getSize().x / 2,
                                               createLabel.getPosition().y - hoveredOption.getSize().y / 2});
    } else if (joinLabel.getGlobalBounds().contains(mouseMoveX, mouseMoveY)) {
        hoveredOption.setPosition(sf::Vector2f{joinLabel.getPosition().x - hoveredOption.getSize().x / 2,
                                               joinLabel.getPosition().y - hoveredOption.getSize().y / 2});
    }
}

void MultiplayerOptions::handleClick(const unsigned int &mouseButtonX, const unsigned int &mouseButtonY) {
    if (createLabel.getGlobalBounds().contains(mouseButtonX, mouseButtonY)) {
        std::cout << "Creating\n";
    } else if (joinLabel.getGlobalBounds().contains(mouseButtonX, mouseButtonY)) {
        std::cout << "Joining " << selectedSettings.joinString << "\n";
    } else if (hoveredColor == white) {
            selectedOption.setPosition(sf::Vector2f{chooseWhite.getPosition().x - selectedOption.getSize().x / 2,
                                                    chooseWhite.getPosition().y - selectedOption.getSize().y / 2});
            selectedSettings.color = white;
    } else {
        selectedOption.setPosition(sf::Vector2f{chooseBlack.getPosition().x - selectedOption.getSize().x / 2,
                                                chooseBlack.getPosition().y - selectedOption.getSize().y / 2});
        selectedSettings.color = black;
    }
}

