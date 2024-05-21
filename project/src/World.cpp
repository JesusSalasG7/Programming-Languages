#include <Settings.hpp>
#include <src/World.hpp>

World::World() noexcept
    : section{sf::Vector2f(Settings::SECTION1_WIDTH, Settings::SECTION1_HEIGHT)},
    ROWS{3},
    COLS{3}
{
     section.setPosition(0, 0);
     section.setFillColor(sf::Color::Red);
     map = {{1, 1, 1},
            {1, 0, 1},
            {1, 0, 0}};

}

void World::update(float dt) noexcept
{

}

void World::render(sf::RenderTarget& target) const noexcept
{
    target.draw(section);

    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLS; x++)
        {
            sf::Sprite sprite;
            if (map[y][x] == Settings::CAMINO)
            {
                sprite.setTexture(Settings::textures["camino"]);
            }
            else if (map[y][x] == Settings::MURO)
            {
                sprite.setTexture(Settings::textures["muro"]);
            }
            sprite.setPosition(x * Settings::TILESIZE, y * Settings::TILESIZE);
            target.draw(sprite);
        }
    }
}