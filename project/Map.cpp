#include "Character.hpp"
#include "Map.hpp"

Map::Map()
{

    for (int i = 0; i < Rows; ++i)
    {
        std::vector<char> row;
        for (int j = 0; j < Columns; ++j)
        {
            row.push_back('0'); 
            std::cout << row[j];
        }
        board.push_back(row); 
        std::cout << std::endl;
    }
}

bool Map::is_obstacle(int i,int j) const 
{
    return Map::board[i][j] == '1';
}

bool Map::is_goal(int i, int j) const
{
    return Map::board[i][j] == '9';
}

std::pair<int, int> Map::get_begin() const
{
    int row = 0;
    int column = 0;

    return std::make_pair(row, column);
}

std::pair<int , int>  Map::get_end() const
{
    int row = Map::rows - 1;
    int column = Map::columns - 1;

    return std::make_pair(row, column);
}