#include "Statement.hpp"
#include "Expression.hpp"
#include "Map.hpp"

#include <cassert>

#include <sstream>

int main(int argc, char const *argv[])
{
    std::stringstream ss{};
    ss << '1' << '0' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1';
    ss << '1' << '0' << '0' << '0' << '1' << '1' << '1' << '1' << '1' << '1';
    ss << '1' << '0' << '1' << '0' << '1' << '1' << '1' << '1' << '1' << '1';
    ss << '1' << '0' << '1' << '0' << '0' << '0' << '1' << '1' << '1' << '1';
    ss << '1' << '1' << '1' << '1' << '1' << '9' << '1' << '1' << '1' << '1';
    ss << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1';
    ss << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1';
    ss << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1';
    ss << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1';
    ss << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1' << '1';

    Environment env{ss, 0, 1, 1, 0};


    std::list<std::shared_ptr<Statement>> program1{};

    program1.push_back(std::make_shared<Move>());
    program1.push_back(std::make_shared<TurnLeft>());
    program1.push_back(std::make_shared<Move>());
    program1.push_back(std::make_shared<Move>());
    program1.push_back(std::make_shared<TurnRight>());
    program1.push_back(std::make_shared<Move>());
    program1.push_back(std::make_shared<Move>());
    program1.push_back(std::make_shared<TurnLeft>());
    program1.push_back(std::make_shared<Move>());
    program1.push_back(std::make_shared<Move>());
    program1.push_back(std::make_shared<TurnRight>());
    program1.push_back(std::make_shared<Move>());
    program1.push_back(std::make_shared<Finish>());
    
    for (auto stmt : program1)
    {
        assert(stmt->execute(env));    
    }

    /*
        for 12
            if (loop == 1)
                turnleft
            else
                if loop == 4
                    turnright
                else
                    if loop == 7
                        turnleft
                    else
                        if loop == 10
                            turnright
                        else
                            move
    */

    std::list<std::shared_ptr<Statement>> program2{};
    auto loop = std::make_shared<Loop>(12);
    loop->add(
        std::make_shared<If>(
            std::make_shared<Equal>(std::make_shared<LoopStep>(loop), std::make_shared<Int>(1)),
            std::list<std::shared_ptr<Statement>>{std::make_shared<TurnLeft>()},
            std::list<std::shared_ptr<Statement>>{
                std::make_shared<If>(
                    std::make_shared<Equal>(std::make_shared<LoopStep>(loop), std::make_shared<Int>(4)),
                    std::list<std::shared_ptr<Statement>>{std::make_shared<TurnRight>()},
                    std::list<std::shared_ptr<Statement>>{
                        std::make_shared<If>(
                            std::make_shared<Equal>(std::make_shared<LoopStep>(loop), std::make_shared<Int>(7)),
                            std::list<std::shared_ptr<Statement>>{std::make_shared<TurnLeft>()},
                            std::list<std::shared_ptr<Statement>>{
                                std::make_shared<If>(
                                    std::make_shared<Equal>(std::make_shared<LoopStep>(loop), std::make_shared<Int>(10)),
                                    std::list<std::shared_ptr<Statement>>{std::make_shared<TurnRight>()},
                                    std::list<std::shared_ptr<Statement>>{std::make_shared<Move>()}
                                )
                            }
                        )
                    }
                )
            }
        )
    );
    program2.push_back(loop);
    program2.push_back(std::make_shared<Finish>());

    env.character = Character{0, 1, 1, 0};

    for (auto stmt : program2)
    {
        assert(stmt->execute(env));
    }
    
    return 0;
}