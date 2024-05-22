#include <Settings.hpp>
#include <src/World.hpp>

World::World() noexcept
    : section{sf::Vector2f(Settings::SECTION1_WIDTH, Settings::SECTION1_HEIGHT)},
    ROWS{6},
    COLS{10},
    player{
        Settings::TILESIZE * 1, Settings::TILESIZE * 1,
        Settings::PLAYER_WIDTH, Settings::PLAYER_HEIGHT
      }
{
     section.setPosition(0, 0);
     section.setFillColor(sf::Color::Red);
     map = {{1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
            {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
            {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {1, 0, 1, 0, 1, 0, 0, 0, 1, 1},
            {0, 1, 0, 0, 1, 0, 0, 9, 1, 1},
            {1, 0, 0, 0, 1, 0, 0, 0, 0, 0}};

}

void World::update(float dt) noexcept
{
    player.update(dt);
}

void World::render(sf::RenderTarget& target) const noexcept
{
    target.draw(section);

    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLS; x++)
        {
            sf::Sprite sprite;
            sprite.setTexture(Settings::textures["camino"]);
            sprite.setPosition(x * Settings::TILESIZE, y * Settings::TILESIZE);
            target.draw(sprite);

            if (map[y][x] == Settings::MURO)
            {
                sprite.setTexture(Settings::textures["muro"]);
                sprite.setPosition(x * Settings::TILESIZE, y * Settings::TILESIZE);
                target.draw(sprite);
            }
            else if (map[y][x] == Settings::META)
            {
                sprite.setTexture(Settings::textures["meta"]);
                sprite.setPosition(x * Settings::TILESIZE, y * Settings::TILESIZE);
                target.draw(sprite);
            }

        }
    }
    player.render(target);
}