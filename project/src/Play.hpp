#pragma once

#include <SFML/Graphics.hpp>
#include <src/PlayButton.hpp>

class Play
{
public:
    Play() noexcept;

    Play(const Play& Play) = delete;

    Play& operator = (Play) = delete;

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

    PlayButton button;

private:
    sf::RectangleShape section;


};
