#include "obstacle.h"

int main()
{
    return 0;
}

// #include <bits/stdc++.h>

// class Obstacle
// {
// };

// class Pit : public Obstacle
// {
// };

// class Breeze : public Obstacle
// {
// };

// class Stench : public Obstacle
// {
// };

// class Glitter : public Obstacle
// {
// };

// class Gold : public Obstacle
// {
// };

// class LiveWumpus : public Obstacle
// {
// };

// class DeadWumpus : public Obstacle
// {
// };

// class ObstacleFactory
// {

// public:
//     ObstacleFactory(std::vector<std::string> &obstacles, std::vector<char> &symbols) throw(char *)
//     {
//         if (obstacles.size() != num_obstacles || symbols.size() != num_obstacles)
//         {
//             throw "Invalid Legend!";
//         }

//         for (int i = 0; i < num_obstacles; ++i)
//         {
//             std::string obstacle = obstacles[i];
//             char symbol = symbols[i];
//             if (legend.find(obstacle) != legend.end())
//             {
//                 throw "Duplicate definition of obstacle " + obstacle + "!";
//             }

//             if (rlegend.find(symbol) != rlegend.end())
//             {
//                 throw "Duplicate definition of obstacle " + obstacle + "'s symbol " + symbol + "!";
//             }

//             legend[obstacle] = symbol;
//             rlegend[symbol] = obstacle;
//         }
//     }

//     Obstacle createObstacle(std::string obstacle) throw(char *)
//     {
//         if (legend.find(obstacle) == legend.end())
//         {
//             throw "There is no obstacle of type '" + obstacle + "'!";
//         }
//     }

// private:
//     const int num_obstacles = 7;
//     std::unordered_map<std::string, char> legend;  // obstacle -> symbol
//     std::unordered_map<char, std::string> rlegend; // symbol -> obstacle
//     const static char **allObstacles{
//         "Pit", "Breeze", "Stench", "Glitter", "Gold", "LiveWumpus", "DeadWumpus"};
// };
