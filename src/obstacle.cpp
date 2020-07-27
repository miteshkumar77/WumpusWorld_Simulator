#include "obstacle.h"



std::unordered_map<std::string, std::function<Obstacle()>> ObstacleFactory::declMap{
    {"Pit", []() { return Pit(); }},
    {"Breeze", []() { return Breeze(); }},
    {"Stench", []() { return Stench(); }},
    {"Glitter", []() { return Glitter(); }},
    {"Gold", []() { return Gold(); }},
    {"LiveWumpus", []() { return LiveWumpus(); }},
    {"DeadWumpus", []() { return DeadWumpus(); }}};

Obstacle ObstacleFactory::createObstacle(std::string obstacleName) throw(char *)
{
    if (declMap.find(obstacleName) != declMap.end())
    {
        return declMap[obstacleName]();
    }
    else
    {
        throw "Obstacle of type " + obstacleName + " does not exist!";
    }
}