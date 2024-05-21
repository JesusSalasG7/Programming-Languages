#pragma once

#include <SFML/Graphics.hpp>
#include <src/Button.hpp>

class Play
{
public:
    Play() noexcept;

    Play(const Play& Play) = delete;

    Play& operator = (Play) = delete;

    void update(float dt, const sf::Vector2i mouse_posicion) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

private:
    sf::RectangleShape section;
    Button button;


};
