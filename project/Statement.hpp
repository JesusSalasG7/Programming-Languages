#include "Map.hpp"
#include "Character.hpp"
#include <list>
#include <memory>

struct Environment
{
    Map map;
    Character character;
};

class Statement
{
public:
    virtual bool execute(Environment &) const = 0;
    virtual ~Statement()
    {

    }
};

class TurnLeft : public Statement
{
public:
    bool execute(Environment &) const override;
};

class TurnRight : public Statement
{
public:
    bool execute(Environment &) const override;
};

class Move : public Statement
{
public:
    bool execute(Environment &) const override;
};

class Loop : public Statement
{
public:
    Loop(int times);
    bool execute(Environment &) const override;
    void add(std::shared_ptr<Statement>);
private:
    std::list< std::shared_ptr<Statement>> repeat;
    int times;
};

class Finish : public Statement
{
public:
    bool execute(Environment &) const override;
};