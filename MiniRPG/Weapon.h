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

public:
    Weapon(std::string name, int damage, int weight, Element element, Rarity rarity, std::string description, bool isTwoHanded = false)
        : Item(name, weight, rarity, description), damage(damage), element(element), isTwoHanded(isTwoHanded) {}

    int getStat() const override { return damage; }
    int getAttack() const override { return damage; }
    int getDefense() const override { return 0; }
    Element getElement() const override { return element; }
    std::string getType() const override { return "Weapon"; }

};
