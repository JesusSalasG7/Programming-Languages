#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <vector>

class Map
{
public:
    Map(std::istream& is);      
    bool is_obstacle(int i,int j) const;
    bool is_goal(int i, int j) const;
    
private:
    static constexpr int Rows = 10;
    static constexpr int Columns = 10;
    char board[Rows][Columns];
};

#endif // MAP_HPP
