#pragma once
#include "Item.h"
#include "Weapon.h"
#include "Element.h"
#include "Rarity.h"

class Armor : public Item {
private:
    int defense;
    Element element;

public:
    Armor(std::string name, int defense, int weight, Element element, Rarity rarity, std::string description)
        : Item(name, weight, rarity, description), defense(defense), element(element) {}
    
    int getStat() const override { return defense; }
    int getAttack() const override { return 0; }
    int getDefense() const override { return defense; }
    Element getElement() const override { return element; }
    std::string getType() const override { return "Armor"; }
};