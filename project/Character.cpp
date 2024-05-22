#include "Character.hpp"

Character::Character(int _position_I, int _position_J, int _direction_I, int _direction_J) noexcept
    :  position_I{_position_I}, position_J{_position_J}, direction_I{_direction_I},  direction_J{ _direction_J}
{
    
}

void Character::turn_left()
{
    int new_direction_I = direction_J * -1;
    direction_J = direction_I;
    direction_I = new_direction_I;
}

void Character::turn_right()
{
    int new_direction_I = direction_J;
    direction_J = direction_I * -1;
    direction_I = new_direction_I;
}

int Character::get_i() const
{
    return position_I;
}

int Character::get_j() const
{
    return position_J;
}

int Character::get_next_i() const
{
    return position_I + direction_I;
}

int Character::get_next_j() const
{
    return position_J + direction_J;
}

int Character::get_direction_i() const
{
    return direction_I;
}

int Character::get_direction_j() const
{
    return direction_J;
}

void Character::move()
{
    int new_position_I = position_I + direction_I;
    int new_position_J = position_J + direction_J;

    position_I = new_position_I;
    position_J = new_position_J;
}
