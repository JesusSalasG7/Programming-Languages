#pragma once

#include <SFML/Graphics.hpp>

class Button
{
public:
    Button(float _x, float _y, float w, float h, sf::String name_file) noexcept;

    //Button(const Button&);

    Button& operator = (Button&) = delete;

    void update(float dt) noexcept;

    bool on_click(sf::Vector2i mouse_posicion) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

private:
    float x;
    float y;
    float width;
    float height;
    sf::Sprite sprite;
};
