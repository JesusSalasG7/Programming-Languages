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

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "move_right.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/move_right.png"};
    }

    Settings::textures["move_right"] = texture;

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "move_left.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/move_left.png"};
    }

    Settings::textures["move_left"] = texture;

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "move_forward.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/move_forward.png"};
    }

    Settings::textures["move_forward"] = texture;

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "move_back.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/move_back.png"};
    }

    Settings::textures["move_back"] = texture;

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "ready_flag.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/ready_flag.png"};
    }

    Settings::textures["ready_flag"] = texture;

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "repeat_end.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/repeat_end.png"};
    }

    Settings::textures["repeat_end"] = texture;
}
