#pragma once
#include "Item.h"
#include "Weapon.h"

class Armor : public Item {
private:
    int defense;  
    Element element;  

public:
    Armor(std::string name, int defense, Element element = Element::None)
        : Item(name), defense(defense), element(element) {}

    int getAttack() const override { return 0; }  

    int getDefense() const override { return defense; }
    Element getElement() const override { return element; }
    std::string getType() const override { return "Armor"; }
};
