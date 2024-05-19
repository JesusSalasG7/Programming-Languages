#include <Settings.hpp>
#include <src/Button.hpp>
#include <iostream>

Button::Button(float x, float y, float width, float height, sf::Font& font, std::string text, sf::Color idle_color, sf::Color hover_color, sf::Color active_color) noexcept
{
    button_state = BTN_IDLE;

    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));
    this->font = font;
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(24);
    this->text.setPosition(
        shape.getPosition().x + (shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
        shape.getPosition().y + (shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
        );

    this->idle_color = idle_color;
    this->hover_color = hover_color;
    this->active_color = active_color;

    shape.setFillColor(this->idle_color);
}

void Button::update(float dt, const sf::Vector2i mouse_posicion) noexcept
{

    if (shape.getGlobalBounds().contains(mouse_posicion.x, mouse_posicion.y)) 
    {
        this->button_state = BTN_HOVER;
        

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->button_state = BTN_ACTIVE;
        }
    }
    else 
    {
        this->button_state = BTN_IDLE;
    }

    switch(button_state)
    {
        case BTN_IDLE:
            shape.setFillColor(idle_color);
        break;

        case BTN_HOVER:
            shape.setFillColor(hover_color);
        break;

        case BTN_ACTIVE:
            shape.setFillColor(active_color);
        break;
    }
}

void Button::render(sf::RenderTarget& target) const noexcept
{
    target.draw(shape);
    target.draw(text);
}