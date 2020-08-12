#include "solver.h"
const std::array<int, 5> dirs{0, 1, 0, -1, 0}; 
const std::array<std::string, 5> translation {
        "move_right", "move_up", "move_left", "move_down", "ERROR"
    }; 


Solver::Solver(int M, int N) {
    gotGold = false; 
    gotArrow = true; 
    rpos = {0, 0}; 
    gameOver = false; 
    board = std::vector<std::vector<Cell>>(M, std::vector<Cell>(N, Cell()));  
}

std::string Solver::move(std::vector<std::string>& messages) {
    updateAfterMove(messages); 
    if (move_queue.empty()) {
        nextMoveSequence(); 
    }
    std::string ans = move_queue.front(); 
    int i = std::find(translation.begin(), translation.end(), ans) - translation.begin(); 
    rpos[0] += dirs[i]; 
    rpos[1] += dirs[i + 1]; 
    move_queue.pop_front(); 
    return ans; 
}


void Solver::nextMoveSequence() {
    if (gotGold) {
        pathTo(0, 0); 
        return; 
    }
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (!board[i][j].visited && board[i][j].livewumpus == -1 && board[i][j].pit == -1) {
                pathTo(i, j); 
                return; 
            }
        } 
    }

    std::cout << "--------DEADLOCK--------" << std::endl; 
}




void Solver::pathTo(int row, int col) {

    std::vector<std::string> path; 

    int M = board.size(); 
    int N = board[0].size();    

    std::vector<std::vector<int>> pre(M, std::vector<int>(N)); 
    std::vector<std::vector<bool>> visited(M, std::vector<bool>(N, false)); 
    int sx = rpos[0]; 
    int sy = rpos[1]; 
    std::queue<std::pair<int, int>> q; 
    visited[sx][sy] = true; 
    q.push(std::make_pair(sx, sy)); 
    while(!q.empty()) {
        int tx = q.front().first; 
        int ty = q.front().second; 
        q.pop(); 

        for (int i = 0; i < 4; ++i) {
            int nx = tx + dirs[i]; 
            int ny = tx + dirs[i + 1]; 
            if (checkPos(nx, ny) && !visited[nx][ny] && board[nx][ny].livewumpus == -1 && board[nx][ny].pit == -1) {

                visited[nx][ny] = true; 
                q.push(std::make_pair(nx, ny)); 
                pre[nx][ny] = i; 
            }
        }
    }


    int cx = row; 
    int cy = col; 
    
    while(cx != sx || cy != sy) {
        path.push_back(translation[pre[cx][cy]]); 
        cx -= dirs[pre[cx][cy]]; 
        cy -= dirs[pre[cx][cy] + 1]; 
    }

    for (std::string s : path) {
        move_queue.push_front(s); 
    }
    // std::reverse(path.begin(), path.end()); 
    // return path; 
}

void Solver::updateAfterMove(std::vector<std::string>& messages) {


    int x = rpos[0]; 
    int y = rpos[1]; 

    board[x][y].visited = true; 
    for (std::string s : messages) {
        if (s == "CONTINUE"){}
        else if (s == "SUCCESS") {
            std::cout << "SUCCEEDED" << std::endl; 
            gameOver = true; 
        } else if (s == "FAIL") {
            std::cout << "FAILED" << std::endl; 
            gameOver = true; 
        } else if (s == "BREEZE") {
            board[x][y].breeze = true; 
        } else if (s == "STENCH") {
            board[x][y].stench = true; 
        } else if (s == "GLITTER") {
            board[x][y].glitter = true; 
        } else if (s == "GOLD") {
            gotGold = true; 
        }
    }

    for (int i = 0; i < 4; ++i) {
        int nx = x + dirs[i]; int ny = y + dirs[i + 1]; 
        if (checkPos(nx, ny)) {
            if (!board[x][y].breeze) {
                board[nx][ny].pit = -1; 
            }
            if (!board[x][y].glitter) {
                board[nx][ny].gold = -1; 
            }
            if (!board[x][y].stench) {
                board[nx][ny].livewumpus = -1; 
            }

            markOneCell(nx, ny); 
        }
    }



}


void Solver::markOneCell(int row, int col) {

    bool hasLiveWumpus = true; 
    bool hasGold = true; 

    for (int i = 0; i < 4; ++i) {
        int nrow = row + dirs[i]; int ncol = col + dirs[i + 1]; 
        if (checkPos(nrow, ncol)) {
            if (!board[nrow][ncol].visited || !board[nrow][ncol].stench) {
                hasLiveWumpus = false; 
            }

            if (!board[nrow][ncol].visited || !board[nrow][ncol].glitter) {
                hasGold = false; 
            }
        }
    }

    if (hasLiveWumpus) {
        board[row][col].livewumpus = 1; 
    }
    if (hasGold) {
        board[row][col].gold = 1; 
    }
}


bool Solver::checkPos(int row, int col) {
    return row >= 0 && col >= 0 && row < 4 && col < 4; 
}

