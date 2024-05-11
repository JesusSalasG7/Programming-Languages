#include <Settings.hpp>
#include <src/ControlPanel.hpp>

ControlPanel::ControlPanel() noexcept
    : section{sf::Vector2f(Settings::SECTION3_WIDTH, Settings::SECTION3_HEIGHT)}
{
     section.setPosition(0, Settings::SECTION1_HEIGHT); 
     section.setFillColor(sf::Color::Blue);
}

void ControlPanel::update(float dt) noexcept
{

}

void ControlPanel::render(sf::RenderTarget& target) const noexcept
{
    target.draw(section);
}