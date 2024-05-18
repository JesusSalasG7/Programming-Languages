#include "Statement.hpp"

Statement::~Statement()
{

}

bool TurnLeft::execute(Environment &e) const
{
    e.character.turn_left();

    return true;
}

bool TurnRight::execute(Environment &e) const
{
    e.character.turn_right();

    return true;
}

bool Move::execute(Environment &e) const
{
    bool obstacle = e.map.is_obstacle(e.character.get_next_i(), e.character.get_next_j());
    
    if (!obstacle)
    {
        e.character.move();
        return true;
    } 

    return false;
}

bool Finish::execute(Environment &e) const
{
    return e.map.is_goal(e.character.get_next_i(), e.character.get_next_j());
}

Loop::Loop (int _times)
    : times{_times}
{

}

bool Loop::execute(Environment &e) const
{
    for(int i = 0; i < times; ++i)
    {
        for (auto s : repeat)
        {
            if (!s->execute(e))
            {
                return false;
            }
            
        }   
    }

    return true;
}

void Loop::add(std::shared_ptr<Statement> s) 
{
    repeat.push_back(s);
}