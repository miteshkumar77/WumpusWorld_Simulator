#ifndef OBSERVER_H
#define OBSERVER_H
#include <bits/stdc++.h>

class Observer
{
public:
    static void update(std::array<std::array<std::unordered_set<std::string>, 4>, 4> &visible_board,
            std::array<int, 2> &robot_position, std::vector<std::string> &messages, bool hasArrow, bool hasGold);
};

#endif