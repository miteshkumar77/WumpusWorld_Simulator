#include "observer.h"

void Observer::update(const std::vector<std::vector<std::unordered_set<std::string>>> &visible_board,
    const std::array<int, 2> &robot_position, const std::vector<std::string> &messages, bool hasArrow, bool hasGold) {
        
    std::cout << messages.size() << '\n'; 
    for(std::string msg : messages) {
        std::cout << msg << '\n'; 
    }
}