#pragma once

#include "Map.hpp"
#include "Character.hpp"
#include <list>
#include <memory>
#include <stack>

class Expression;

struct Environment
{
    Map map;
    Character character;

    Environment(std::istream &is, int pi, int pj, int di, int dj);
};

class Statement
{
public:
    virtual bool execute(Environment &) = 0;
    virtual ~Statement()
    {

    }
};

class TurnLeft : public Statement
{
public:
    bool execute(Environment &) override;
};

class TurnRight : public Statement
{
public:
    bool execute(Environment &) override;
};

class Move : public Statement
{
public:
    bool execute(Environment &) override;
};

class Loop : public Statement
{
public:
    Loop(int times, const std::list< std::shared_ptr<Statement>>& _repeat);
    bool execute(Environment &) override;
    void add(std::shared_ptr<Statement>);
    int get_current_step() const;
private:
    std::list< std::shared_ptr<Statement>> repeat;
    int current_step = 0;
    int times;
};

class Finish : public Statement
{
public:
    bool execute(Environment &) override;
};

class If : public Statement
{
public:
    If(std::shared_ptr<Expression> cond, std::list<std::shared_ptr<Statement>> then, std::list<std::shared_ptr<Statement>> els);
    
    bool execute(Environment &) override;
private:
    std::shared_ptr<Expression> condition;
    std::list<std::shared_ptr<Statement>> then_block;
    std::list<std::shared_ptr<Statement>> else_block;
};

using Scope = std::list<std::shared_ptr<Statement>>;
using Program = std::stack<Scope>;