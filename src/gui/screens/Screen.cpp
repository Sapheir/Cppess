// Created by Catalin
#include "Screen.h"

Screen::Screen(sf::RenderWindow& window, sf::Font& font, const unsigned int &fontSize, screens &nextScreen)
      : window{window}, font{font}, fontSize{fontSize}, nextScreen{nextScreen} {}
