#include "Armor.h"

Armor::Armor(std::string name, int defense, Element element)
    : Item(name), defense(defense), element(element) {}

int Armor::getDefense() const {
    return defense;
}

Element Armor::getElement() const {
    return element;
}

std::string Armor::getType() const {
    return "Armor";
}