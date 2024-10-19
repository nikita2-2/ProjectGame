#pragma once
#include <iostream>
class Player {
public:
    Player(const std::string& name) : name(name), score(0) {}

    std::string getName() const { return name; }
    int getScore() const { return score; }

    void addScore(int points) { score += points; }

private:
    std::string name;
    int score;
};


