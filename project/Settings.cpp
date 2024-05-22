#include <stdexcept>

#include <Settings.hpp>

const fs::path Settings::GRAPHICS_PATH{"graphics"};
const fs::path Settings::FONTS_PATH{"fonts"};

std::unordered_map<std::string, sf::Texture> Settings::textures{};
sf::Font Settings::font;

void Settings::init()
{
    Settings::load_textures();
    Settings::load_font();
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

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "turn_right.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/turn_right.png"};
    }

    Settings::textures["turn_right"] = texture;

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "turn_left.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/turn_left.png"};
    }

    Settings::textures["turn_left"] = texture;

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

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "hole.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/hole.png"};
    }

    Settings::textures["muro"] = texture;

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "ice.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/ice.png"};
    }

    Settings::textures["camino"] = texture;

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "goal.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/goal.png"};
    }

    Settings::textures["meta"] = texture;

}

void Settings::load_font()
{
    if (!font.loadFromFile(Settings::FONTS_PATH / "font.ttf"))
    {
        throw std::runtime_error{"Error loading font"};
    } 
}