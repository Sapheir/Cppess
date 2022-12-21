#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <asio.hpp>

int main()
{
    // SFML test
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello SFML!");
    // Start the game loop
    while (window.isOpen())
    {
        // Process Events
        sf::Event event{};
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}