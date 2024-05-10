#pragma once

struct Settings
{
    static constexpr int WINDOW_WIDTH{640};
    static constexpr int WINDOW_HEIGHT{480};
    static constexpr int SECTION1_WIDTH{WINDOW_WIDTH - WINDOW_WIDTH / 4};
    static constexpr int SECTION1_HEIGHT{WINDOW_HEIGHT - WINDOW_HEIGHT / 4};
    static constexpr int SECTION2_WIDTH{WINDOW_WIDTH / 4};
    static constexpr int SECTION2_HEIGHT{WINDOW_HEIGHT - WINDOW_HEIGHT / 4};
    static constexpr int SECTION3_WIDTH{WINDOW_WIDTH};
    static constexpr int SECTION3_HEIGHT{WINDOW_HEIGHT / 4};
    static constexpr int SECTION4_WIDTH{WINDOW_WIDTH / 4};
    static constexpr int SECTION4_HEIGHT{WINDOW_HEIGHT / 4};

    static void init();
    static void load_textures();
};

