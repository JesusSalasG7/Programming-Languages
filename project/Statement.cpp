#include "Statement.hpp"
#include "Expression.hpp"

Environment::Environment(std::istream& is, int pi, int pj, int di, int dj)
    : map{is}, character{pi, pj, di, dj}
{
    
}

bool TurnLeft::execute(Environment &e)
{
    e.character.turn_left();

    return true;
}

bool TurnRight::execute(Environment &e)
{
    e.character.turn_right();

    return true;
}

bool Move::execute(Environment &e)
{
    bool obstacle = e.map.is_obstacle(e.character.get_next_i(), e.character.get_next_j());
    
    if (!obstacle)
    {
        e.character.move();
        return true;
    } 

    return false;
}

bool Finish::execute(Environment &e)
{
    return e.map.is_goal(e.character.get_i(), e.character.get_j());
}

Loop::Loop (int _times, const std::list< std::shared_ptr<Statement>>& _repeat)
    : times{_times}, repeat{_repeat}
{

}

bool Loop::execute(Environment &e)
{
    for(current_step = 0; current_step < times; ++current_step)
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

int Loop::get_current_step() const 
{
    return current_step;
}

If::If(std::shared_ptr<Expression> _condition, std::list<std::shared_ptr<Statement>> _then, std::list<std::shared_ptr<Statement>> _else)
    : condition{_condition}, then_block{_then}, else_block{_else}
{

}

bool If::execute(Environment &e)
{
    auto cond = std::dynamic_pointer_cast<Int>(condition->eval(e));

    if (cond->get_value() == 1)
    {
        for (auto s : then_block)
        {
            if (!s->execute(e))
            {
                return false;
            }
        }
    }
    else
    {
        for (auto s : else_block)
        {
            if (!s->execute(e))
            {
                return false;
            }
        }
    }
    return true;
}