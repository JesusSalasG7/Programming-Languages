#pragma once

#include <filesystem>
#include <string>
#include <unordered_map>

namespace fs = std::filesystem;

#include <SFML/Graphics.hpp>

struct Settings
{
    static const fs::path GRAPHICS_PATH;
    static const fs::path FONTS_PATH;

    static constexpr int WINDOW_WIDTH{1280};
    static constexpr int WINDOW_HEIGHT{740};
    static constexpr int VIRTUAL_WIDTH{1280};
    static constexpr int VIRTUAL_HEIGHT{740};
    static constexpr float PLAYER_WIDTH{32.f};
    static constexpr float PLAYBUTTON_HEIGHT{88.f};
    static constexpr float PLAYBUTTON_WIDTH{130.f};
    static constexpr float MOVE_RIGHT_HEIGHT{73.f};
    static constexpr float MOVE_RIGHT_WIDTH{290.f};
    static constexpr float PLAYER_HEIGHT{32.f};
    static constexpr int SECTION1_WIDTH{VIRTUAL_WIDTH - VIRTUAL_WIDTH / 4};
    static constexpr int SECTION1_HEIGHT{VIRTUAL_HEIGHT - VIRTUAL_HEIGHT / 4};
    static constexpr int SECTION2_WIDTH{VIRTUAL_WIDTH / 4};
    static constexpr int SECTION2_HEIGHT{VIRTUAL_HEIGHT - VIRTUAL_HEIGHT / 4};
    static constexpr int SECTION3_WIDTH{SECTION1_WIDTH};
    static constexpr int SECTION3_HEIGHT{VIRTUAL_HEIGHT / 4};
    static constexpr int SECTION4_WIDTH{SECTION2_WIDTH};
    static constexpr int SECTION4_HEIGHT{VIRTUAL_HEIGHT / 4};
    static constexpr int CAMINO{0};
    static constexpr int MURO{1};
    static constexpr int TILESIZE{32};

    static std::unordered_map<std::string, sf::Texture> textures;
    static sf::Font font;

    static void init();
    static void load_textures();
    static void load_font();
};

