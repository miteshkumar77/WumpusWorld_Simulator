#ifndef GAME_H
#define GAME_H
#include <bits/stdc++.h>
#include <cxxabi.h>
#include "obstacle.h"
#include "observer.h"

class Game
{
protected:
    std::vector<std::vector<std::unordered_set<std::string>>> invisible_board;
    std::vector<std::vector<std::unordered_set<std::string>>> visible_board;
    int M;
    int N; 
    std::array<int, 2> robot_position;
    bool hasArrow;
    bool foundGold; 
    bool finished; 
    ObstacleFactory obstacleFactory; 
    std::list<Observer *> observers;
    void checkRep() throw(char *);
    void broadcastStateOnMove();
    void broadcastStateOnShoot(int up, int right); 
    void notifyObservers(std::vector<std::vector<std::unordered_set<std::string>>> &visible_board,
            std::array<int, 2> &robot_position, std::vector<std::string> &messages, bool hasArrow, bool hasGold);
    void updateVisitedSquares();
    bool checkPosition(const std::array<int, 2>& position); 
public:
    Game();
    void startGame(std::vector<std::vector<std::unordered_set<std::string>>> start_board); 
    void resetGame(std::vector<std::vector<std::unordered_set<std::string>>>& start_board);
    

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


#endif