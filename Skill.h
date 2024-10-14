#pragma once
#include <string>

class Skill {
private:
    std::string name;
    int damage;
    int staminaCost;
    bool isHealing;
    bool isElemental;
    bool isBuffAttack;
    bool isBuffDefense;

public:
    Skill(std::string name, int damage, int staminaCost, bool isElemental = false, bool isHealing = false, bool isBuffAttack = false, bool isBuffDefense = false)
        : name(name), damage(damage), staminaCost(staminaCost), 
        isElemental(isElemental), isHealing(isHealing), isBuffAttack(isBuffAttack), isBuffDefense(isBuffDefense) {}

    std::string getName() const { return name; }
    int getDamage() const { return damage; }
    int getStaminaCost() const { return staminaCost; }
    bool getIsElemental() const { return isElemental; }
    bool getIsHealing() const { return isHealing; }
    bool getIsBuffAttack() const { return isBuffAttack; }
    bool getIsBuffDefense() const { return isBuffDefense; }
};
