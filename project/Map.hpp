#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <vector>

class Map
{
public:
    Map();       
    std::pair<int, int> get_begin() const;
    std::pair<int, int> get_end() const;
    bool is_obstacle(int i,int j) const;
    
private:
    static constexpr int Rows = 20;
    static constexpr int Columns = 20;
    static constexpr int rows = Rows;
    static constexpr int columns = Columns;
    std::vector<std::vector<char>> board;
    std::pair<int, int> begin;
    std::pair<int, int> end;
};

#endif // MAP_HPP
