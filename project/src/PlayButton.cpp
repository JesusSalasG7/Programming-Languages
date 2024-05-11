#include <Settings.hpp>
#include <src/PlayButton.hpp>

PlayButton::PlayButton(float _x, float _y, float w, float h) noexcept
    : x{_x}, y{_y}, width{w}, height{h}, sprite{Settings::textures["PlayButton"]}
{
    sprite.setPosition(x, y);
}

void PlayButton::update(float dt) noexcept
{

}

void PlayButton::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
}