#include "game.h"
#include "observer.h"

int main()
{
    Observer o1; 
    std::vector<std::vector<std::unordered_set<std::string>>> start_invis_board(4, std::vector<std::unordered_set<std::string>>(4, std::unordered_set<std::string>())); 
    start_invis_board[2][0].insert("LiveWumpus"); 
    start_invis_board[2][1].insert("Gold"); 
    start_invis_board[0][2].insert("Pit"); 
    start_invis_board[2][2].insert("Pit"); 
    start_invis_board[3][3].insert("Pit"); 

    Game g1; 
    g1.subscribeObserver(&o1); 

    g1.startGame(start_invis_board); 
    std::string nextMove; 
    while(1) {
        std::cout << std::endl; 
        std::cin >> nextMove; 
        if (nextMove == "move_up") {
            g1.moveRobotUp(); 
        } else if (nextMove == "move_down") {
            g1.moveRobotDown(); 
        } else if (nextMove == "move_right") {
            g1.moveRobotRight(); 
        } else if (nextMove == "move_left") {
            g1.moveRobotLeft(); 
        } else if (nextMove == "shoot_up") {
            g1.shootArrowUp(); 
        } else if (nextMove == "shoot_down") {
            g1.shootArrowDown(); 
        } else if (nextMove == "shoot_left") {
            g1.shootArrowLeft(); 
        } else if (nextMove == "shoot_right") {
            g1.shootArrowRight(); 
        } else {
            std::cout << "INVALID_MOVE, exiting..." << std::endl; 
            return 0;  
        }
        std::cout << std::endl; 
    }
    return 0;
}

// /*
//  * LiveWumpus
//  * DeadWumpus
//  * Pit
//  * Gold
//  * /