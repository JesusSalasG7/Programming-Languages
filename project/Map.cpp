#include "Character.hpp"
#include "Map.hpp"

Map::Map(std::istream& is)
{
    for (int i = 0; i < Rows; ++i)
    {
        for (int j = 0; j < Columns; ++j)
        {
            is >> board[i][j];
        }
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