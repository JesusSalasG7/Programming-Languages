#include <Settings.hpp>
#include <src/Game.hpp>

Game::Game()
    : render_window{sf::VideoMode{Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT}, "Lenguage", sf::Style::Close},
      render_texture{},
      render_sprite{},
      section2{sf::Vector2f(Settings::SECTION2_WIDTH, Settings::SECTION2_HEIGHT)},
      section3{sf::Vector2f(Settings::SECTION3_WIDTH, Settings::SECTION3_HEIGHT)},
      section4{sf::Vector2f(Settings::SECTION4_WIDTH, Settings::SECTION4_HEIGHT)},
      player{
        Settings::VIRTUAL_WIDTH / 2 - Settings::PLAYER_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 2 - Settings::PLAYER_HEIGHT / 2,
        Settings::PLAYER_WIDTH, Settings::PLAYER_HEIGHT
      },
      world{}
      
{
    render_texture.create(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT);

    sf::Vector2f scale_factors{
        float(Settings::WINDOW_WIDTH) / float(Settings::VIRTUAL_WIDTH), 
        float(Settings::WINDOW_HEIGHT) / float(Settings::VIRTUAL_HEIGHT)
    };

    render_sprite.setTexture(render_texture.getTexture());
    render_sprite.setScale(scale_factors);

    section2.setPosition(Settings::SECTION1_WIDTH, 0); 
    section3.setPosition(0, Settings::SECTION1_HEIGHT);
    section4.setPosition(Settings::SECTION1_WIDTH, Settings::SECTION1_HEIGHT);

    section2.setFillColor(sf::Color::Green);
    section3.setFillColor(sf::Color::Blue);
    section4.setFillColor(sf::Color::Yellow);
}

sf::RenderWindow& Game::get_window() noexcept
{
    return render_window;
}

void Game::update(float dt) noexcept
{
    world.update(dt);
}

void Game::render() noexcept
{
    render_texture.clear(sf::Color::Black);
    render_texture.draw(section2);
    render_texture.draw(section3);
    render_texture.draw(section4);
    world.render(render_texture);
    player.render(render_texture);
    render_texture.display();

    render_window.draw(render_sprite);
    render_window.display();
}