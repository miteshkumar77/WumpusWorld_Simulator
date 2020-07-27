#ifndef GAME_H
#define GAME_H
#include <bits/stdc++.h>
#include <cxxabi.h>
#include "obstacle.h"
#include "observer.h"

class Game
{
protected:
    std::array<std::array<std::unordered_set<std::string>, 4>, 4> invisible_board;
    std::array<std::array<std::unordered_set<std::string>, 4>, 4> visible_board;
    std::array<int, 2> robot_position;
    bool hasArrow;
    bool foundGold; 
    ObstacleFactory obstacleFactory; 
    std::list<Observer *> observers;
    void checkRep() throw(char *);
    void broadcastStateOnMove();
    void broadcastStateOnShoot(bool up, bool right); 
    void notifyObservers(std::array<std::array<std::unordered_set<std::string>, 4>, 4> &visible_board,
            std::array<int, 2> &robot_position, std::vector<std::string> &messages, bool hasArrow, bool hasGold);
    void updateVisitedSquares();
public:
    Game(std::array<std::array<std::unordered_set<std::string>, 4>, 4> start_board);
    void resetGame(std::array<std::array<std::unordered_set<std::string>, 4>, 4> start_board);
    

    void subscribeObserver(Observer *observer) throw (char *);

    void moveRobotUp();
    void moveRobotDown();
    void moveRobotLeft();
    void moveRobotRight();

    void shootArrowUp();
    void shootArrowDown();
    void shootArrowLeft();
    void shootArrowRight();

    

};

bool checkPosition(const std::array<int, 2>& position); 
#endif