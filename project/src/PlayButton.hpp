#pragma once

#include <SFML/Graphics.hpp>

class PlayButton
{
public:
    PlayButton(float _x, float _y, float w, float h) noexcept;

    PlayButton(const PlayButton&) = delete;

    PlayButton& operator = (PlayButton&) = delete;

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

private:
    float x;
    float y;
    float width;
    float height;
    sf::Sprite sprite;
};
