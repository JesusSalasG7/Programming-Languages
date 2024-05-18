#include "Statement.hpp"

Statement::~Statement()
{

}

void TurnLeft::execute(Environment &e) const
{
    e.character.turn_left();
}

void TurnRight::execute(Environment &e) const
{
    e.character.turn_right();
}

void Move::execute(Environment &e) const
{
    bool obstacle = e.map.is_obstacle(e.character.get_next_i(), e.character.get_next_j());
    
    if (!obstacle)
    {
        e.character.move();
    } 
}

void Finish::execute(Environment &e) const
{
    //nada
}

Loop::Loop (int _times)
    : times{_times}
{

}

void Loop::execute(Environment &e) const
{
    for(int i = 0; i < times; ++i)
    {
        for (auto s : repeat)
        {
            s->execute(e);
        }
        
    }
}

void Loop::add(std::shared_ptr<Statement> s) 
{
    repeat.push_back(s);
}