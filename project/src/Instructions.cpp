#include <Settings.hpp>
#include <src/Instructions.hpp>

Instructions::Instructions() noexcept
    : section{sf::Vector2f(Settings::SECTION2_WIDTH, Settings::SECTION2_HEIGHT)}
{
     section.setPosition(Settings::SECTION1_WIDTH, 0); 
     section.setFillColor(sf::Color::Green);
}

void Instructions::update(float dt) noexcept
{

}

void Instructions::render(sf::RenderTarget& target) const noexcept
{
    target.draw(section);
}