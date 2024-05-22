#pragma once

#include <SFML/Graphics.hpp>

#include <src/World.hpp>
#include <src/ControlPanel.hpp>
#include <src/Instructions.hpp>
#include <src/Play.hpp>

class Game
{
public:
    Game();

    Game(const Game&) = delete;

    Game& operator = (Game) = delete;

    sf::RenderWindow& get_window() noexcept;

    void update(float dt, const sf::Vector2i mouse_posicion) noexcept;

    void render() noexcept;

private:
    sf::RenderWindow render_window;
    sf::RenderTexture render_texture;
    sf::Sprite render_sprite;

    World world;
    ControlPanel control_panel;
    Instructions instructions;
    Play play;

};
