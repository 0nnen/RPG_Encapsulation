#include "Skill.h"

Skill::Skill(std::string name, int staminaCost, int damage, bool isElemental)
    : name(name), staminaCost(staminaCost), damage(damage), isElemental(isElemental) {}

int Skill::getStaminaCost() const {
    return staminaCost;
}

int Skill::getDamage() const {
    return damage;
}

bool Skill::isSkillElemental() const {
    return isElemental;
}

std::string Skill::getName() const {
    return name;
}
