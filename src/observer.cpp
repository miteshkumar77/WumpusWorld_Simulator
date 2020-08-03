#include "observer.h"
#include <bits/stdc++.h>

void Observer::update(std::array<std::array<std::unordered_set<std::string>, 4>, 4> &visible_board,
    std::array<int, 2> &robot_position, std::vector<std::string> &messages, bool hasArrow, bool hasGold) {
        
    std::cout << messages.size() << '\n'; 
    for(std::string msg : messages) {
        std::cout << msg << '\n'; 
    }
}