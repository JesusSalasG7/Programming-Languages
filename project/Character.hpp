#include "Map.hpp"

class Character
{
    public:

        Character(int _direction_I, int _direction_J, int _position_I, int _position_J) noexcept; 
        void turn_left();
        void turn_right();
        void move();
        int get_next_i() const; //Position i
        int get_next_j() const; //Position j
        ~Character();
    
    private:
        
        int position_I;
        int position_J;
        int direction_I;
        int direction_J;
};
