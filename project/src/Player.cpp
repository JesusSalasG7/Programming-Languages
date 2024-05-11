#include <Settings.hpp>
#include <src/Player.hpp>

Player::Player(float _x, float _y, float w, float h) noexcept
    : x{_x}, y{_y}, width{w}, height{h}, sprite{Settings::textures["player"]}
{
    sprite.setPosition(x, y);
}

void Player::update(float dt) noexcept
{

}

void Player::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
}