#include "Expression.hpp"
#include "Statement.hpp"

Int::Int(int v) : value{v} {}

std::shared_ptr<Expression> Int::eval(Environment& env) 
{
    return std::make_shared<Int>(value);
}

int Int::get_value() const 
{
    return value;
}

LoopStep::LoopStep(std::shared_ptr<Statement> s) : loop_statement{s} {}

std::shared_ptr<Expression> LoopStep::eval(Environment& env) {
    return std::make_shared<Int>(std::dynamic_pointer_cast<Loop>(loop_statement)->get_current_step());
}

Equal::Equal(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) : left{l}, right{r} {}

std::shared_ptr<Expression> Equal::eval(Environment& env) 
{
    auto l = left->eval(env);
    auto r = right->eval(env);

    auto lv = std::dynamic_pointer_cast<Int>(l);
    auto rv = std::dynamic_pointer_cast<Int>(r);

    if (lv->get_value() == rv->get_value()) {
        return std::make_shared<Int>(1);
    } else {
        return std::make_shared<Int>(0);
    }
}