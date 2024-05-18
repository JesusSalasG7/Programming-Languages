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

bool Button::on_click(sf::Vector2i mouse_posicion) noexcept
{
    return mouse_posicion.x >= this->x && mouse_posicion.x <= this->x + this->width  && 
    mouse_posicion.y >= this->y && mouse_posicion.y <= this->y + this->height;
}

void Button::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
}