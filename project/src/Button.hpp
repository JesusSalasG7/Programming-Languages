#pragma once

#include <SFML/Graphics.hpp>

class Button
{
public:
    Button(float _x, float _y, float w, float h, sf::String name_file) noexcept;

    Button(const Button&) = delete;

    Button& operator = (Button&) = delete;

    void update(float dt) noexcept;

    void on_click() noexcept;

    void render(sf::RenderTarget& target) const noexcept;

private:
    float x;
    float y;
    float width;
    float height;
    sf::Sprite sprite;
};
