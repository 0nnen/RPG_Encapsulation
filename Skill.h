#pragma once
#include <string>

class Skill {
private:
    std::string name;
    int staminaCost;
    int damage;
    bool isElemental;

public:
    Skill(std::string name, int staminaCost, int damage, bool isElemental = false);
    int getStaminaCost() const;
    int getDamage() const;
    bool isSkillElemental() const;
    std::string getName() const;
};
