#include "game.h"


Game::Game(std::array<std::array<std::unordered_set<std::string>, 4>, 4> start_board) {
    resetGame(start_board); 
    observers = std::list<Observer *>(); 
}


void Game::resetGame(std::array<std::array<std::unordered_set<std::string>, 4>, 4> start_board) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            visible_board[i][j] = std::unordered_set<std::string>(); 
        }
    }
    invisible_board = start_board; 
    robot_position = std::array<int, 2>{0, 0}; 
    hasArrow = true; 
    foundGold = false; 
}



void Game::subscribeObserver(Observer *observer) throw (char *) {
    if (std::find(observers.begin(), observers.end(), observer) != observers.end()) {
        throw "Tried to subscribe an observer twice to the same game!"; 
    } else {
        observers.push_back(observer); 
    }
}



void Game::broadcastStateOnShoot(bool up, bool right) {
    std::vector<std::string> messages; 
    messages.push_back("SHOOT");

    if (!hasArrow) {
        messages.push_back("NO-MORE-ARROWS");
        notifyObservers(visible_board, robot_position, messages, hasArrow, foundGold); 
        return; 
    }

    std::array<int, 5> dirs{0, 1, 0, -1, 0}; 
    int rxi = robot_position[0]; 
    int ryi = robot_position[1]; 

    int axi = rxi + up; 
    int ayi = ryi + right; 
    hasArrow = false; 
    invisible_board[axi][ayi].insert("Arrow");
    visible_board[axi][ayi].insert("Arrow"); 
    if (invisible_board[axi][ayi].find("LiveWumpus") != invisible_board[axi][ayi].end()) {
        invisible_board[axi][ayi].erase("LiveWumpus"); 
        invisible_board[axi][ayi].insert("DeadWumpus");
        visible_board[axi][ayi].insert("DeadWumpus"); 
        messages.push_back("KILLED-WUMPUS");
        for (int i = 0; i < 4; ++i) {
            
            if (checkPosition(std::array<int, 2>{axi + dirs[i], ayi + dirs[i + 1]})) {
                invisible_board[axi + dirs[i]][ayi + dirs[i + 1]].erase("Stench");
                visible_board[axi + dirs[i]][ayi + dirs[i + 1]].erase("Stench"); 
            }
        }
    } else {
        messages.push_back("MISSED-WUMPUS"); 
    }

    notifyObservers(visible_board, robot_position, messages, hasArrow, foundGold); 

}

void Game::broadcastStateOnMove() {
    std::vector<std::string> messages; 
    int rxi = robot_position[0]; 
    int ryi = robot_position[1];
    if (!checkPosition(robot_position)) {
        messages.push_back("FAIL"); 
        messages.push_back("OUT-OF-BOUNDS");
        notifyObservers(visible_board, robot_position, messages, hasArrow, foundGold); 
        return; 
    }


    if (invisible_board[rxi][ryi].find("Pit") != invisible_board[rxi][ryi].end()) {
        messages.push_back("FAIL"); 
        messages.push_back("PIT");
        visible_board[rxi][ryi].insert("Pit"); 
        notifyObservers(visible_board, robot_position, messages, hasArrow, foundGold); 
        return; 
    }

    if (invisible_board[rxi][ryi].find("LiveWumpus") != invisible_board[rxi][ryi].end()) {
        messages.push_back("FAIL"); 
        messages.push_back("LIVE-WUMPUS");
        visible_board[rxi][ryi].insert("LiveWumpus"); 
        notifyObservers(visible_board, robot_position, messages, hasArrow, foundGold); 
        return; 
    }

    if (foundGold && rxi == 0 && ryi == 0) {
        messages.push_back("SUCCESS"); 
        notifyObservers(visible_board, robot_position, messages, hasArrow, foundGold); 
        return; 
    }

    messages.push_back("CONTINUE"); 
    if (invisible_board[rxi][ryi].find("Breeze") != invisible_board[rxi][ryi].end()) {
        messages.push_back("BREEZE"); 
        visible_board[rxi][ryi].insert("Breeze"); 
    }

    if (invisible_board[rxi][ryi].find("Stench") != invisible_board[rxi][ryi].end()) {
        messages.push_back("STENCH");
        visible_board[rxi][ryi].insert("Stench"); 
    }

    if (invisible_board[rxi][ryi].find("Glitter") != invisible_board[rxi][ryi].end()) {
        messages.push_back("GLITTER");
        visible_board[rxi][ryi].insert("Glitter"); 
    }

    if (invisible_board[rxi][ryi].find("Gold") != invisible_board[rxi][ryi].end()) {
        messages.push_back("GOLD");
        visible_board[rxi][ryi].insert("Gold"); 
    }

    notifyObservers(visible_board, robot_position, messages, hasArrow, foundGold); 

}

void Game::notifyObservers(std::array<std::array<std::unordered_set<std::string>, 4>, 4> &visible_board,
            std::array<int, 2> &robot_position, std::vector<std::string> &messages, bool hasArrow, bool hasGold) {
    for (Observer* observer : observers) {
        observer -> update(visible_board, robot_position, messages, hasArrow, hasGold); 
    }
}


bool checkPosition(const std::array<int, 2>& position) {
    return position[0] >= 0 && position[1] >= 0 &&  position[0] < 4 && position[1] < 4; 
}