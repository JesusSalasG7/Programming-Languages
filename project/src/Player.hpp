#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
    Player(float _x, float _y, float w, float h) noexcept;

    Player(const Player&) = delete;

    Player& operator = (Player&) = delete;

    void render(sf::RenderWindow& window) const noexcept;

private:
    float x;
    float y;
    float width;
    float height;
    sf::Sprite sprite;
};
