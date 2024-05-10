#include <SFML/Window.hpp>
#include "Settings.hpp"

int main()
{   
    Settings::init();

    sf::Window window{sf::VideoMode{Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT}, "languages", sf::Style::Close};

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }
        }
    }

    return EXIT_SUCCESS;
}
