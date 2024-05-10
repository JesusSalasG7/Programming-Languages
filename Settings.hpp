#pragma once

struct Settings
{
    static constexpr int WINDOW_WIDTH{1280};
    static constexpr int WINDOW_HEIGHT{720};

    static void init();
    static void load_textures();
};

