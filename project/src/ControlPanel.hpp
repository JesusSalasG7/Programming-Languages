#pragma once

#include <SFML/Graphics.hpp>
#include <src/Button.hpp>
#include <list>

class ControlPanel
{
public:
    ControlPanel() noexcept;

    ControlPanel(const ControlPanel& ControlPanel) = delete;

    ControlPanel& operator = (ControlPanel) = delete;

    void update(float dt, const sf::Vector2i mouse_posicion) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

private:
    sf::RectangleShape section;
    Button button1, button2, button3, button4, button5, button6;
    std::list<Button> buttons;
};
