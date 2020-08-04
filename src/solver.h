#ifndef SOLVER_H
#define SOLVER_H
#include <bits/stdc++.h>
class Solver {
public:
    void move(std::vector<std::string>& messages); 
    Solver(); 
private: 
    std::vector<std::string> path(int row, int col); 
    void markCells(std::vector<std::string>& messages); 
    void markOneCell(int row, int col); 
    bool checkPos(int row, int col); 



    struct Cell; 
    std::array<int, 2> rpos; 
    std::array<std::array<Cell, 4>, 4> board; 
    bool gotGold; 
    bool gotArrow; 
    bool gameOver; 

}; 


#endif 