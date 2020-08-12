#ifndef SOLVER_H
#define SOLVER_H
#include <bits/stdc++.h>
class Solver {
public:
    std::string move(std::vector<std::string>& messages); 
    Solver(int M, int N); 
private: 
    void updateAfterMove(std::vector<std::string>& messages); 
    void markOneCell(int row, int col); 
    bool checkPos(int row, int col); 
    void nextMoveSequence(); 
    void pathTo(int row, int col); 

    std::list<std::string> move_queue; 

    struct Cell {
        bool stench; 
        bool glitter; 
        bool breeze; 

        // -1: Guaranteed to not be in the cell
        //  0: Cannot be certain
        //  1: Certain that it is in the cell 
        int gold; 
        int livewumpus; 
        int pit; 
        
        bool visited;  


        Cell() {
            stench = false; 
            breeze = false; 
            glitter = false; 
            int gold = 0; 
            int livewumpus = 0; 
            int pit = 0; 
            bool visited = false; 
        }
    };
    std::array<int, 2> rpos; 
    std::vector<std::vector<Cell>> board; 
    bool gotGold; 
    bool gotArrow; 
    bool gameOver; 

}; 


#endif 