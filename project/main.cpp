#include <SFML/Window.hpp>
#include <Settings.hpp>
#include <src/Player.hpp>

int main()
{   
    Settings::init();

    sf::RenderWindow window{sf::VideoMode{Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT}, "languages", sf::Style::Close};
    sf::RenderTexture render_texture{};
    render_texture.create(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT);

    sf::Vector2f scale_factors{
        float(Settings::WINDOW_WIDTH) / float(Settings::VIRTUAL_WIDTH), 
        float(Settings::WINDOW_HEIGHT) / float(Settings::VIRTUAL_HEIGHT)
    };

    sf::Sprite render_sprite{render_texture.getTexture()};
    render_sprite.setScale(scale_factors);

    // Definir los rectángulos para las tres secciones
    sf::RectangleShape section1(sf::Vector2f(Settings::SECTION1_WIDTH, Settings::SECTION1_HEIGHT));
    sf::RectangleShape section2(sf::Vector2f(Settings::SECTION2_WIDTH, Settings::SECTION2_HEIGHT));
    sf::RectangleShape section3(sf::Vector2f(Settings::SECTION3_WIDTH, Settings::SECTION3_HEIGHT));
    sf::RectangleShape section4(sf::Vector2f(Settings::SECTION4_WIDTH, Settings::SECTION4_HEIGHT));

    // Establecer las posiciones de las secciones
    section1.setPosition(0, 0);
    section2.setPosition(Settings::SECTION1_WIDTH, 0); 
    section3.setPosition(0, Settings::SECTION1_HEIGHT);
    section4.setPosition(Settings::SECTION1_WIDTH, Settings::SECTION1_HEIGHT);

    // Establecer colores diferentes para cada sección
    section1.setFillColor(sf::Color::Red);
    section2.setFillColor(sf::Color::Green);
    section3.setFillColor(sf::Color::Blue);
    section4.setFillColor(sf::Color::Yellow);

    // Define al personaje principal
    Player player{
        Settings::VIRTUAL_WIDTH / 2 - Settings::PLAYER_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 2 - Settings::PLAYER_HEIGHT / 2,
        Settings::PLAYER_WIDTH, Settings::PLAYER_HEIGHT
    };

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

        render_texture.clear(sf::Color::Black);
        render_texture.draw(section1);
        render_texture.draw(section2);
        render_texture.draw(section3);
        render_texture.draw(section4);
        player.render(render_texture);
        render_texture.display();

        window.draw(render_sprite);
        window.display();
    }

    return EXIT_SUCCESS;
}
