#include <Settings.hpp>
#include <src/World.hpp>

World::World() noexcept
    : section{sf::Vector2f(Settings::SECTION1_WIDTH, Settings::SECTION1_HEIGHT)}
{
     section.setPosition(0, 0);
     section.setFillColor(sf::Color::Red);
}

void World::update(float dt) noexcept
{

}

void World::render(sf::RenderTarget& target) const noexcept
{
    target.draw(section);
}