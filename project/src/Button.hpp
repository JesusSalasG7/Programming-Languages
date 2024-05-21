#pragma once

#include <SFML/Graphics.hpp>

class Button
{
public:
    Button(float x, float y, float width, float height, sf::Font& font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) noexcept;

    //Button(const Button&);

    Button& operator = (Button&) = delete;

    void update(float dt, const sf::Vector2i mouse_posicion) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

private:
    short unsigned button_state;
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;

    sf::Color idle_color;
    sf::Color hover_color;
    sf::Color active_color;

    enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};
};
