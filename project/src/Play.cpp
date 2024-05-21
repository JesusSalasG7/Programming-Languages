#include <Settings.hpp>
#include <src/Play.hpp>

Play::Play() noexcept
    : section{sf::Vector2f(Settings::SECTION4_WIDTH, Settings::SECTION4_HEIGHT)},

    button{
        Settings::SECTION1_WIDTH, Settings::SECTION1_HEIGHT + 20,
        Settings::MOVE_RIGHT_WIDTH, Settings::MOVE_RIGHT_HEIGHT,
        Settings::font, "Play", sf::Color::Green, sf::Color::Yellow, sf::Color::Red,
        [] (Program& p) {
            
        }
    }
{
     section.setPosition(Settings::SECTION1_WIDTH, Settings::SECTION1_HEIGHT); 
     section.setFillColor(sf::Color::Yellow);
}

void Play::update(float dt, const sf::Vector2i mouse_posicion) noexcept
{
    button.update(dt, mouse_posicion);
}

void Play::render(sf::RenderTarget& target) const noexcept
{
    target.draw(section);
    button.render(target);
}