#include <Settings.hpp>
#include <src/World.hpp>

World::World() noexcept
    : section1{sf::Vector2f(Settings::SECTION1_WIDTH, Settings::SECTION1_HEIGHT)}
{
     section1.setPosition(0, 0);
     section1.setFillColor(sf::Color::Red);
}

void World::update(float dt) noexcept
{

}

void World::render(sf::RenderTarget& target) const noexcept
{
    target.draw(section1);
}