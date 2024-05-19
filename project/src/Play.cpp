#include <Settings.hpp>
#include <src/Play.hpp>

Play::Play() noexcept
    : section{sf::Vector2f(Settings::SECTION4_WIDTH, Settings::SECTION4_HEIGHT)}
{
     section.setPosition(Settings::SECTION1_WIDTH, Settings::SECTION1_HEIGHT); 
     section.setFillColor(sf::Color::Yellow);
}

void Play::update(float dt) noexcept
{

}

void Play::render(sf::RenderTarget& target) const noexcept
{
    target.draw(section);
    //button.render(target);
}