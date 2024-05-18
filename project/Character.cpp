#include "Character.hpp"

Character::Character(int _direction_I, int _direction_J, int _position_I, int _position_J) noexcept
    :  direction_I{_direction_I},  direction_J{ _direction_J}, position_I{_position_I}, position_J{_position_J}
{
    
}

void Character::turn_left()
{
    direction_I = position_J * -1; 
    direction_J = position_I;
}

void Character::turn_right()
{
    direction_I = position_J;
    direction_J = position_I * -1;
}

int Character::get_next_i() const
{
    return position_I + direction_I;
}

int Character::get_next_j() const
{
    return position_J + direction_J;
}

void Character::move()
{
    int new_position_I = position_I + direction_I;
    int new_position_J = position_J + direction_J;

    position_I = new_position_I;
    position_J = new_position_J;
}
