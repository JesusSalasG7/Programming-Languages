#pragma once

#include <SFML/Graphics.hpp>

class ControlPanel
{
public:
    ControlPanel() noexcept;

    ControlPanel(const ControlPanel& ControlPanel) = delete;

    ControlPanel& operator = (ControlPanel) = delete;

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

private:
    sf::RectangleShape section;

};
