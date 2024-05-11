#pragma once

#include <SFML/Graphics.hpp>

class Instructions
{
public:
    Instructions() noexcept;

    Instructions(const Instructions& Instructions) = delete;

    Instructions& operator = (Instructions) = delete;

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

private:
    sf::RectangleShape section;

};
