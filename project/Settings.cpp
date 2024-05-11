#include <stdexcept>

#include <Settings.hpp>

const fs::path Settings::GRAPHICS_PATH{"graphics"};

std::unordered_map<std::string, sf::Texture> Settings::textures{};

void Settings::init()
{
    Settings::load_textures();
}

void Settings::load_textures()
{
    sf::Texture texture{};

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "player.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/player.png"};
    }

    Settings::textures["player"] = texture;

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "PlayButton.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/PlayButton.png"};
    }

    Settings::textures["PlayButton"] = texture;


}
