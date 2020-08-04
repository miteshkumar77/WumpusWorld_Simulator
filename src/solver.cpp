#include "solver.h"
const std::array<int, 5> dirs{0, 1, 0, -1, 0}; 
struct Solver::Cell {
    bool stench; 
    bool breeze; 
    bool glitter; 
    bool gold; 
    bool livewumpus; 
    bool pit; 
    bool safe; 
    bool visited; 

    Cell() {
        stench = false; 
        breeze = false; 
        glitter = false; 
        gold = false; 
        livewumpus = false; 
        pit = false; 
        safe = false; 
        visited = false; 
    }
};

Solver::Solver() {
    gotGold = false; 
    gotArrow = false; 
    rpos = {0, 0}; 
    gameOver = false; 
}

void Solver::markCells(std::vector<std::string>& messages) {
    board[rpos[0]][rpos[1]].visited = true; 
    board[rpos[0]][rpos[1]].safe = true; 
    for (std::string s : messages) {
        if (s == "CONTINUE"){}
        if (s == "FAIL") {
            gameOver = true; 
        }
        else if (s == "BREEZE") {
            board[rpos[0]][rpos[1]].breeze = true; 
        }
        else if (s == "STENCH") {
            board[rpos[0]][rpos[1]].stench = true; 
        }

        else if (s == "GLITTER") {
            board[rpos[0]][rpos[1]].glitter = true; 
        } 
        
    }
}


void Solver::markOneCell(int row, int col) {

    bool hasPit = true; 
    bool hasGold = true; 
    bool hasWumpus = true; 
    for (int i = 0; i < 4; ++i) {
        int nrow = row + dirs[i]; int ncol = col + dirs[i + 1]; 
        if (checkPos(nrow, ncol)) {
            if (!board[nrow][ncol].stench) {
                hasWumpus = false; 
            }

            if (!board[nrow][ncol].breeze) {
                hasPit = false; 
            }

            if (!board[nrow][ncol].glitter) {
                hasGold = false; 
            }

            if (board[nrow][ncol].visited && !board[nrow][ncol].stench &&
            !board[nrow][ncol].breeze) {

                board[row][col].safe = true; 
            }
        }
    }
}


bool Solver::checkPos(int row, int col) {
    return row >= 0 && col >= 0 && row < 4 && col < 4; 
}

