#include <Settings.hpp>
#include <src/Game.hpp>

Game::Game()
    : render_window{sf::VideoMode{Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT}, "Lenguage", sf::Style::Close},
      render_texture{},
      render_sprite{},
      player{
        Settings::VIRTUAL_WIDTH / 2 - Settings::PLAYER_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 2 - Settings::PLAYER_HEIGHT / 2,
        Settings::PLAYER_WIDTH, Settings::PLAYER_HEIGHT
      },
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

void Game::update(float dt) noexcept
{
    player.update(dt);
    world.update(dt);
    control_panel.update(dt);
    instructions.update(dt);
    play.update(dt);
}

void Game::on_click(sf::Vector2i mouse_posicion) noexcept
{
    control_panel.on_click(mouse_posicion);

}

void Game::render() noexcept
{
    render_texture.clear(sf::Color::Black);
    world.render(render_texture);
    player.render(render_texture);
    control_panel.render(render_texture);
    instructions.render(render_texture);
    play.render(render_texture);
    render_texture.display();

    render_window.draw(render_sprite);
    render_window.display();
}