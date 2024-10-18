#pragma once 
#include "Item.h"
#include <iostream>
#include "Element.h" 

class Weapon : public Item {
private:
    int damage;
    bool isTwoHanded;
    Element element;

public:
    Weapon(std::string name, int damage, bool isTwoHanded, Element element = Element::None)
        : Item(name), damage(damage), isTwoHanded(isTwoHanded), element(element) {}

    int getDamage() const { return damage; } 

    int getAttack() const override { return damage; }  

    int getDefense() const override { return 0; }

    bool getIsTwoHanded() const { return isTwoHanded; }
    Element getElement() const override { return element; }

    std::string getType() const override { return "Weapon"; }
};
