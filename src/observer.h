#ifndef OBSERVER_H
#define OBSERVER_H
#include <bits/stdc++.h>

class Observer
{
public:
    void update(const std::vector<std::vector<std::unordered_set<std::string>>> &visible_board,
            const std::array<int, 2> &robot_position, const std::vector<std::string> &messages, bool hasArrow, bool hasGold);
};

#endif