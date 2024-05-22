#pragma once

#include "Statement.hpp"
#include <memory>

struct Environment;
class Statement;

class Expression
{
public:
    virtual std::shared_ptr<Expression> eval(Environment& e) = 0;
};

class Int : public Expression
{
public:
    Int(int v);

    int get_value() const;

    std::shared_ptr<Expression> eval(Environment& e) override;   

private:
    int value;
};

class LoopStep : public Expression
{
public:
    LoopStep(std::shared_ptr<Statement> loop_stmt);

    std::shared_ptr<Expression> eval(Environment& e) override;

private:
    std::shared_ptr<Statement> loop_statement;  
};

class Equal : public Expression
{
public:
    Equal(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);

    std::shared_ptr<Expression> eval(Environment& e) override;

private:
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;
};