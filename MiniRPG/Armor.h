#pragma once
#include "Item.h"
#include "Weapon.h"

class Armor : public Item {
private:
    int defense;  // Défense physique de l'armure
    Element element;  // Élément de résistance de l'armure

public:
    Armor(std::string name, int defense, Element element = Element::None)
        : Item(name), defense(defense), element(element) {}

    // Redéfinition de getAttack()
    int getAttack() const override { return 0; }  // L'armure n'a pas d'attaque

    int getDefense() const override { return defense; }
    Element getElement() const override { return element; }
    std::string getType() const override { return "Armor"; }
};
