#pragma once
#include "Item.h"
#include "Weapon.h"
#include "Element.h"
#include "Rarity.h"

class Armor : public Item {
private:
    int defense;
    Element element;
    Rarity rarity;
    int weight;
    std::string description;

public:
    Armor(std::string name, int defense, int weight, Element element, Rarity rarity, std::string description)
        : Item(name), defense(defense), weight(weight), element(element), rarity(rarity), description(description) {}

    int getAttack() const override { return 0; }
    int getDefense() const override { return defense; }
    Element getElement() const override { return element; }
    std::string getType() const override { return "Armor"; }
    Rarity getRarity() const { return rarity; }
    int getWeight() const { return weight; }
    std::string getDescription() const { return description; }
};
