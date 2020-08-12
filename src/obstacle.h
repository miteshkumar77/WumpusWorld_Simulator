#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <bits/stdc++.h>
class Obstacle
{
};

class Pit : public Obstacle
{
};

class Breeze : public Obstacle
{
};

class Stench : public Obstacle
{
};

class Glitter : public Obstacle
{
};

class Gold : public Obstacle
{
};

class LiveWumpus : public Obstacle
{
};

class DeadWumpus : public Obstacle
{
};

class ObstacleFactory
{
private:
    const static int num_obstacles = 7;
    static std::unordered_map<std::string, std::function<Obstacle()>> declMap;

public:
    Obstacle createObstacle(std::string obstacleName) throw(char *);
};

#endif