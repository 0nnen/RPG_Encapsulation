#pragma once
#include "Item.h"
#include "Weapon.h"

class Armor : public Item {
private:
    int defense;  // D�fense physique de l'armure
    Element element;  // �l�ment de r�sistance de l'armure

public:
    Armor(std::string name, int defense, Element element = Element::None)
        : Item(name), defense(defense), element(element) {}

    int getDefense() const { return defense; };
    Element getElement() const { return element; };
    std::string getType() const override { return "Armor"; };
};
