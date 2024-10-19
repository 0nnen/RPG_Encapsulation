#pragma once
#include "Item.h"
#include <iostream>
#include "Element.h"
#include "Rarity.h"

class Weapon : public Item {
private:
    int damage;
    bool isTwoHanded;
    Element element;
    Rarity rarity;
    int weight;
    std::string description;

public:
    Weapon(std::string name, int damage, int weight, Element element, Rarity rarity, std::string description, bool isTwoHanded = false)
        : Item(name), damage(damage), weight(weight), element(element), rarity(rarity), description(description), isTwoHanded(isTwoHanded) {}

    int getDamage() const { return damage; }
    int getAttack() const override { return damage; }
    int getDefense() const override { return 0; }
    Element getElement() const override { return element; }
    std::string getType() const override { return "Weapon"; }
    Rarity getRarity() const { return rarity; }
    int getWeight() const { return weight; }
    std::string getDescription() const { return description; }
};
