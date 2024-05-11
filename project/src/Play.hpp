#pragma once

#include <SFML/Graphics.hpp>

class Play
{
public:
    Play() noexcept;

    Play(const Play& Play) = delete;

    Play& operator = (Play) = delete;

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

private:
    sf::RectangleShape section;

};
