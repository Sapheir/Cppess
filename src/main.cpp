#include "gui/GUI.h"
#include <iostream>

int main()
{
    try {
        GUI gui;
        gui.run();
    } catch (std::exception &exception) {
        std::cerr << exception.what() << "\n";
    }
    return 0;
}