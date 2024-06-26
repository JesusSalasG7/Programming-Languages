#include <Settings.hpp>
#include <src/Game.hpp>

Game::Game()
    : render_window{sf::VideoMode{Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT}, "Lenguage", sf::Style::Close},
      render_texture{},
      render_sprite{},
      world{},
      control_panel{},
      instructions{},
      play{}
      
{
    render_texture.create(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT);

    sf::Vector2f scale_factors{
        float(Settings::WINDOW_WIDTH) / float(Settings::VIRTUAL_WIDTH), 
        float(Settings::WINDOW_HEIGHT) / float(Settings::VIRTUAL_HEIGHT)
    };

    render_sprite.setTexture(render_texture.getTexture());
    render_sprite.setScale(scale_factors);
}

sf::RenderWindow& Game::get_window() noexcept
{
    return render_window;
}

void Game::update(float dt, const sf::Vector2i mouse_posicion) noexcept
{
    world.update(dt);
    control_panel.update(dt, mouse_posicion);
    instructions.update(dt);
    play.update(dt, mouse_posicion);
}

void Game::render() noexcept
{
    render_texture.clear(sf::Color::Black);
    world.render(render_texture);
    control_panel.render(render_texture);
    instructions.render(render_texture);
    play.render(render_texture);
    render_texture.display();

    render_window.draw(render_sprite);
    render_window.display();
}