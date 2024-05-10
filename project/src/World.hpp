#pragma once

#include <SFML/Graphics.hpp>

class World
{
public:
    World() noexcept;

    World(const World& world) = delete;

    World& operator = (World) = delete;

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

private:
    sf::RectangleShape section1;

};
