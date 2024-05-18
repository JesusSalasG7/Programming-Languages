#include <Settings.hpp>
#include <src/Button.hpp>

Button::Button(float _x, float _y, float w, float h, sf::String name_file) noexcept
    : x{_x}, y{_y}, width{w}, height{h}, sprite{Settings::textures[name_file]}
{
    sprite.setPosition(x, y);
}

void Button::update(float dt) noexcept
{

}

void Button::on_click() noexcept
{

}

void Button::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
}