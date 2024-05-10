#pragma once

#include <filesystem>
#include <string>
#include <unordered_map>

namespace fs = std::filesystem;

#include <SFML/Graphics.hpp>

struct Settings
{
    static const fs::path GRAPHICS_PATH;

    static constexpr int WINDOW_WIDTH{640};
    static constexpr int WINDOW_HEIGHT{480};
    static constexpr float PLAYER_WIDTH{32.f};
    static constexpr float PLAYER_HEIGHT{32.f};
    static constexpr int SECTION1_WIDTH{WINDOW_WIDTH - WINDOW_WIDTH / 4};
    static constexpr int SECTION1_HEIGHT{WINDOW_HEIGHT - WINDOW_HEIGHT / 4};
    static constexpr int SECTION2_WIDTH{WINDOW_WIDTH / 4};
    static constexpr int SECTION2_HEIGHT{WINDOW_HEIGHT - WINDOW_HEIGHT / 4};
    static constexpr int SECTION3_WIDTH{WINDOW_WIDTH};
    static constexpr int SECTION3_HEIGHT{WINDOW_HEIGHT / 4};
    static constexpr int SECTION4_WIDTH{WINDOW_WIDTH / 4};
    static constexpr int SECTION4_HEIGHT{WINDOW_HEIGHT / 4};

    static std::unordered_map<std::string, sf::Texture> textures;

    static void init();
    static void load_textures();
};

