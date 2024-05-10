#pragma once

#include <SFML/Graphics.hpp>

#include <src/Player.hpp>
#include <src/World.hpp>

class Game
{
public:
    Game();

    Game(const Game&) = delete;

    Game& operator = (Game) = delete;

    sf::RenderWindow& get_window() noexcept;

    void update(float dt) noexcept;

    void render() noexcept;

private:
    sf::RenderWindow render_window;
    sf::RenderTexture render_texture;
    sf::Sprite render_sprite;

    sf::RectangleShape section2;
    sf::RectangleShape section3;
    sf::RectangleShape section4;
    
    Player player;
    World world;
    
};
