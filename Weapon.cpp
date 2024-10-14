#include "Weapon.h"

int Weapon::getDamage() const {
    return damage;
}

bool Weapon::getIsTwoHanded() const {
    return isTwoHanded;
}

Element Weapon::getElement() const {
    return element;
}

std::string Weapon::getName() const {
    return name;
}

std::string Weapon::getType() const {
    return "Weapon";
}