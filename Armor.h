#pragma once
#include "Item.h"
#include "Weapon.h"

class Armor : public Item {
private:
    int defense;  // Défense physique de l'armure
    Element element;  // Élément de résistance de l'armure

public:
    Armor(std::string name, int defense, Element element = Element::None);

    int getDefense() const;
    Element getElement() const;
    std::string getType() const override;
};
